#pragma region game include
#include "PlayerPawn.h"  
#include "Animation/PlayerAnimation.h"
#include "../../Gameplay/Interact/Base/InteractBase.h"
#include "../../Gameplay/Moveable/Moveable.h"
#include "../../Gameplay/DetectiveView/DetectiveView.h"
#include "../../UI/Logbook/Logbook.h"
#pragma endregion

#pragma region UE4 include
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Camera/CameraComponent.h"
#pragma endregion
#pragma region helper
#include "DrawDebugHelpers.h"  
#pragma endregion


// Sets default values
APlayerPawn::APlayerPawn()
{
	// enable update every frame
	PrimaryActorTick.bCanEverTick = true;

	// create default scene component and make root
	USceneComponent* pRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = pRoot;

	// create default capsule component and attach to root
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule->SetupAttachment(pRoot);

	// create default skeletal mesh component and attach to capsule
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Capsule);

	// create default scene component and attach to capsule
	CameraRoot = CreateDefaultSubobject<USceneComponent>(TEXT("CamRoot"));
	CameraRoot->SetupAttachment(Capsule);

	// create default camera component and attach to camera root
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraRoot);
}

void APlayerPawn::SetLogbook(ULogbook* Logbook)
{
	m_pLogbook = Logbook;
	m_pLogbook->SetVisibility(ESlateVisibility::Hidden);
}

void APlayerPawn::ShowHideLogbook(bool Visible)
{
	if (Visible)
	{
		m_pLogbook->SetVisibility(ESlateVisibility::Visible);

		((APlayerController*)(GetController()))->bShowMouseCursor = true;

		FInputModeGameAndUI im;
		im.SetLockMouseToViewportBehavior(EMouseLockMode::LockInFullscreen);
		((APlayerController*)(GetController()))->SetInputMode(im);
	}
	else
	{
		m_pLogbook->SetVisibility(ESlateVisibility::Hidden);

		((APlayerController*)(GetController()))->bShowMouseCursor = false;
		FInputModeGameOnly im;
		((APlayerController*)(GetController()))->SetInputMode(im);
	}
}

void APlayerPawn::AddLogbookEntry(int ID, FString Text)
{
	m_pLogbook->AddEntry(ID, Text);
	m_pLogbook->UpdateEntries();
}

void APlayerPawn::AddImageLogbookEntry(int ID, UTexture2D* Image)
{
	m_pLogbook->AddEntry(ID, Image);
	m_pLogbook->UpdateEntries();
}

void APlayerPawn::Move(FVector2D Movement, bool Running)
{
	if (Movement.X != 0.0f || Movement.Y != 0.0f)
	{
		if (Running && !m_pAnimation->IsRun)
		{
			m_pAnimation->IsIdle = false;
			m_pAnimation->IsWalk = false;
			m_pAnimation->IsRun = true;
		}
		else if (!Running && !m_pAnimation->IsWalk)
		{
			m_pAnimation->IsIdle = false;
			m_pAnimation->IsRun = false;
			m_pAnimation->IsWalk = true;
		}
	}
	else
	{
		if (!m_pAnimation->IsIdle)
		{
			m_pAnimation->IsRun = false;
			m_pAnimation->IsWalk = false;
			m_pAnimation->IsIdle = true;
		}
	}

	if (Running)
		Movement *= 2.0f;

	float positionZ = Capsule->GetComponentLocation().Z;

	FVector movement = Capsule->GetForwardVector() * Movement.Y * Speed * GetWorld()->GetDeltaSeconds();
	movement += Capsule->GetRightVector() * Movement.X * Speed * GetWorld()->GetDeltaSeconds();
	movement.Z += 1.0f;

	FHitResult moveResult;

	Capsule->AddWorldOffset(movement, true, &moveResult);

	Capsule->SetWorldLocation(FVector(Capsule->GetComponentLocation().X, Capsule->GetComponentLocation().Y, positionZ));

	if (moveResult.bBlockingHit)
		if (moveResult.GetActor() && moveResult.GetActor()->ActorHasTag("Moveable"))
			if (((AMoveable*)(moveResult.GetActor()))->Move(FVector(movement.X, movement.Y, 0.0f)))
				Capsule->AddWorldOffset(movement);

	FHitResult hit;

	FVector startPos = Capsule->GetComponentLocation();
	startPos += Capsule->GetForwardVector() * Movement.Y * Capsule->GetScaledCapsuleRadius();
	startPos += Capsule->GetRightVector() * Movement.X * Capsule->GetScaledCapsuleRadius();

	FVector endPos = startPos - FVector(0.0f, 0.0f, Capsule->GetScaledCapsuleHalfHeight());

	GetWorld()->LineTraceSingleByChannel(hit, startPos, endPos, ECollisionChannel::ECC_Visibility);

	if (hit.bBlockingHit)
	{
		FVector pos = Capsule->GetComponentLocation();
		pos.Z = hit.Location.Z + Capsule->GetScaledCapsuleHalfHeight();

		Capsule->SetWorldLocation(pos);
		m_fallTime = 0.0f;
	}
	else
	{
		m_fallTime += GetWorld()->GetDeltaSeconds();

		FVector pos = Capsule->GetComponentLocation();
		pos.Z -= m_fallTime * 981.0f * GetWorld()->GetDeltaSeconds();

		FHitResult resultFall;
		Capsule->SetWorldLocation(pos, true, &resultFall);

		if (resultFall.bBlockingHit)
			m_fallTime = 0.0f;
	}
}

void APlayerPawn::Rotate(FVector2D _rotation)
{
	// get current camera pitch, add rotation and clamp angle
	float angle = CameraRoot->RelativeRotation.Pitch;
	angle += _rotation.Y * RotationSpeed * GetWorld()->GetDeltaSeconds();
	angle = FMath::Max(-45.0f, FMath::Min(45.0f, angle));

	// set pitch of camera root and add rotation to capsule yaw
	CameraRoot->SetRelativeRotation(FRotator(angle, CameraRoot->RelativeRotation.Yaw, 0.0f));
	Capsule->AddLocalRotation(FRotator(0.0f, _rotation.X * RotationSpeed * GetWorld()->GetDeltaSeconds(), 0.0f));
}

void APlayerPawn::Interact()
{
	// save hit result from line trace from camera forward
	FHitResult result;
	GetWorld()->LineTraceSingleByChannel(result, Camera->GetComponentLocation(),
		Camera->GetComponentLocation() + Camera->GetForwardVector() * 300.0f, ECollisionChannel::ECC_Camera);

	// try to cast hit actor to interact base
	AInteractBase* pInteract = Cast<AInteractBase>(result.GetActor());

	// if interact base valid call interact from hit actor
	if (pInteract)
		pInteract->Interact(this);
}

void APlayerPawn::ActivateView()
{

	TArray<FHitResult> hits;
	FCollisionShape MySphere = FCollisionShape::MakeSphere(500.0f);

	FVector start = Capsule->GetComponentLocation();
	FVector end = Capsule->GetComponentLocation() + FVector(5.0f, 5.0f, 5.0f);

	//DrawDebugSphere(GetWorld(), Capsule->GetComponentLocation(), MySphere.GetSphereRadius(), 100, FColor::Purple, true);

	GetWorld()->SweepMultiByChannel(hits, start, end, FQuat::Identity, ECollisionChannel::ECC_Camera, MySphere);
	
	for (auto& Hit : hits)
	{
		if (Hit.bBlockingHit)
		{
			if (Hit.GetActor() && Hit.GetActor()->ActorHasTag("View"))
			{
				((ADetectiveView*)(Hit.GetActor()))->ActivateShader();
			}
		}
	}

}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();

	m_pAnimation = (UPlayerAnimation*)Mesh->GetAnimInstance();
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


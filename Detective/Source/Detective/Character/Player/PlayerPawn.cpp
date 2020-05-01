#pragma region game include
#include "PlayerPawn.h"  
#include "../../Gameplay/Interact/Base/InteractBase.h"
#pragma endregion

#pragma region UE4 include
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Camera/CameraComponent.h"
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

void APlayerPawn::Move(FVector2D _movement)
{
	// calculate location to add to capsule by movement and movement speed
	FVector movement = Capsule->GetForwardVector() * _movement.Y * Speed * GetWorld()->GetDeltaSeconds();
	movement += Capsule->GetRightVector() * _movement.X * Speed * GetWorld()->GetDeltaSeconds();
	movement.Z += 1.0f;

	// movement hit result
	FHitResult moveResult;

	// try to add world offset by movement
	Capsule->AddWorldOffset(movement, true, &moveResult);

	// if movement blocking
	/*if (moveResult.bBlockingHit)
		// if hit actopr valid and has tag moveable
		if (moveResult.GetActor() && moveResult.GetActor()->ActorHasTag("Moveable"))
			// call move on moveable actor
			if (((AMoveable*)(moveResult.GetActor()))->Move(FVector(movement.X, movement.Y, 0.0f)))
				// if moveable actor moved move player
				Capsule->AddWorldOffset(movement);*/

	// raycast hit for movement vertical
	FHitResult hit;

	// calculate start position of raycast
	FVector startPos = Capsule->GetComponentLocation() - FVector(0.0f, 0.0f, 45.0f);
	startPos += Capsule->GetForwardVector() * _movement.Y * Capsule->GetUnscaledCapsuleRadius();
	startPos += Capsule->GetRightVector() * _movement.X * Capsule->GetUnscaledCapsuleRadius();

	// set end position of raycast down
	FVector endPos = startPos - FVector(0.0f, 0.0f, 45.0f);

	// raycast down
	GetWorld()->LineTraceSingleByChannel(hit, startPos, endPos, ECollisionChannel::ECC_Visibility);

	// if raycast blocking hit and hit is upper feet
	if (hit.bBlockingHit && hit.Distance <= 40.0f)
	{
		// position to set
		FVector pos = Capsule->GetComponentLocation();
		pos.Z = hit.Location.Z + Capsule->GetUnscaledCapsuleHalfHeight() + 5.0f;

		// set position to hit location and reset fall time
		Capsule->SetWorldLocation(pos);
		m_fallTime = 0.0f;
	}

	// if no blocking hit or below player
	else
	{
		// increase fall time
		m_fallTime += GetWorld()->GetDeltaSeconds();

		// calculate next position below
		FVector pos = Capsule->GetComponentLocation();
		pos.Z -= m_fallTime * 981.0f * GetWorld()->GetDeltaSeconds();

		// try to move down and save hit result of fall
		FHitResult resultFall;
		Capsule->SetWorldLocation(pos, true, &resultFall);

		// if blocking hit reset fall time
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
		Camera->GetComponentLocation() + Camera->GetForwardVector() *250.0f, ECollisionChannel::ECC_Camera);

	// try to cast hit actor to interact base
	AInteractBase* pInteract = Cast<AInteractBase>(result.GetActor());

	// if interact base valid call interact from hit actor
	if (pInteract)
		pInteract->Interact(this);
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
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


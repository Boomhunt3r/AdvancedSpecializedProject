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
	FVector movement = Capsule->GetForwardVector() * _movement.Y * Speed * GetWorld()->GetDeltaSeconds();
	movement += Capsule->GetRightVector() * _movement.X * Speed * GetWorld()->GetDeltaSeconds();

	Capsule->AddWorldOffset(movement, true);
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


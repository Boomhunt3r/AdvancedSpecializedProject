// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"

#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	USceneComponent* pRoot = CreateEditorOnlyDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = pRoot;

	Capsule = CreateAbstractDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule->SetupAttachment(pRoot);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Capsule);

	CameraRoot = CreateDefaultSubobject<USceneComponent>(TEXT("CamRoot"));
	CameraRoot->SetupAttachment(Capsule);

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
	float angle = CameraRoot->RelativeRotation.Pitch;
	angle += _rotation.Y * RotationSpeed * GetWorld()->GetDeltaSeconds();
	angle = FMath::Max(-45.0f, FMath::Min(45.0f, angle));

	CameraRoot->SetRelativeRotation(FRotator(angle, CameraRoot->RelativeRotation.Yaw, 0.0f));
	Capsule->AddLocalRotation(FRotator(0.0f, _rotation.X * RotationSpeed * GetWorld()->GetDeltaSeconds(), 0.0f));
}

void APlayerPawn::Interact()
{
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


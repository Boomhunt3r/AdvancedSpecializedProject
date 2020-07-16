#pragma region game include
#include "PlayerCharacter.h"  
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
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#pragma endregion

// Sets default values
APlayerCharacter::APlayerCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(37.5f, 95.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void APlayerCharacter::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

void APlayerCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void APlayerCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent)

	PlayerInputComponent->BindAxis("ForwardBack", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("LeftRight", this, &APlayerCharacter::MoveRight);

	PlayerInputComponent->BindAxis("RotateLeftRight", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("RotateUpDown", this, &APawn::AddControllerPitchInput);

	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void APlayerCharacter::SetLogbook(ULogbook* Logbook)
{
	m_pLogbook = Logbook;
	m_pLogbook->SetVisibility(ESlateVisibility::Hidden);
}

void APlayerCharacter::ShowHideLogbook(bool Visible)
{
	if (Visible)
	{
		m_pLogbook->SetVisibility(ESlateVisibility::Visible);

		((APlayerController*)(GetController()))->bShowMouseCursor = true;

		FInputModeGameAndUI im;
		im.SetLockMouseToViewportBehavior(EMouseLockMode::LockInFullscreen);
		((APlayerController*)(GetController()))->SetInputMode(im);
		/*m_pAnimation->IsIdle = true;
		m_pAnimation->IsWalk = false;
		m_pAnimation->IsRun = false;*/
	}
	else
	{
		m_pLogbook->SetVisibility(ESlateVisibility::Hidden);

		((APlayerController*)(GetController()))->bShowMouseCursor = false;
		FInputModeGameOnly im;
		((APlayerController*)(GetController()))->SetInputMode(im);
	}
}

void APlayerCharacter::AddLogbookEntry(int ID, FString Text)
{
	m_pLogbook->AddEntry(ID, Text);
	m_pLogbook->UpdateEntries();
}

void APlayerCharacter::AddImageLogbookEntry(int ID, UTexture2D* Image)
{
	m_pLogbook->AddEntry(ID, Image);
	m_pLogbook->UpdateEntries();
}

void APlayerCharacter::AddClearLogbookEntry(int ID, UTexture2D* Image)
{
	m_pLogbook->AddClearEntry(ID, Image);
}

void APlayerCharacter::Interact()
{
	// save hit result from line trace from camera forward
	FHitResult result;
	GetWorld()->LineTraceSingleByChannel(result, FollowCamera->GetComponentLocation(),
		FollowCamera->GetComponentLocation() + FollowCamera->GetForwardVector() * 200.0f, ECollisionChannel::ECC_Camera);

	// try to cast hit actor to interact base
	AInteractBase* pInteract = Cast<AInteractBase>(result.GetActor());

	// if interact base valid call interact from hit actor
	if (pInteract)
		pInteract->Interact(this);
}

void APlayerCharacter::ActivateView(TArray<AActor*> _View)
{
	float VectorLength;

	for (AActor* Actor : _View)
	{
		VectorLength = (Actor->GetActorLocation() - GetCapsuleComponent()->GetComponentLocation()).Size();

		if (VectorLength <= 500.0f)
			((ADetectiveView*)(Actor))->ActivateShader();
	}
}


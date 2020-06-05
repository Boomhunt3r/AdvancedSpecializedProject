#pragma once

#pragma region UE4 include
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"  
#pragma endregion


#pragma region game include
#include "PlayerPawn.generated.h"  
#pragma endregion


#pragma region forward decleration
class UCapsuleComponent;
class UCameraComponent;
class ULogbook;
class UPlayerAnimation;
#pragma endregion


UCLASS()
class DETECTIVE_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

public:
#pragma region public override function
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
#pragma endregion

#pragma region UPROPERTY
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Player")
		UCapsuleComponent* Capsule = nullptr;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Player")
		USkeletalMeshComponent* Mesh = nullptr;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Player")
		USceneComponent* CameraRoot = nullptr;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Player")
		UCameraComponent* Camera = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Player Movement")
		float Speed = 0.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Player Movement")
		float RotationSpeed = 0.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Player Movement")
		float JumpForce = 0.0f;
#pragma endregion

#pragma region UFUNCTION
	UFUNCTION(BlueprintCallable, Category = "Player")
	void SetLogbook(ULogbook* Logbook);

	UFUNCTION(BlueprintCallable, Category = "Player")
	void ShowHideLogbook(bool Visible);

	UFUNCTION(BlueprintCallable, Category = "Player")
	void AddLogbookEntry(int ID, FString Text);

	UFUNCTION(BlueprintCallable, Category = "Player")
	void AddImageLogbookEntry(int ID, UTexture2D* Image);

	UFUNCTION(BlueprintCallable, Category = "Player Movement")
	void Move(FVector2D Movement, bool Running);

	UFUNCTION(BlueprintCallable, Category = "Player Movement")
	void Rotate(FVector2D _rotation);

	UFUNCTION(BlueprintCallable, Category = "Player Action")
	void Interact();

	UFUNCTION(BlueprintCallable, Category = "Player Action")
	void ActivateView();
#pragma endregion


protected:
#pragma region protected pointer
	ULogbook* m_pLogbook = nullptr;

	UPlayerAnimation* m_pAnimation = nullptr;
#pragma endregion


#pragma region protected primitive variable
	/// <summary>
	/// fall time in seconds
	/// </summary>
	float m_fallTime = 0.0f;
#pragma endregion

#pragma region protected override function
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
#pragma endregion
};

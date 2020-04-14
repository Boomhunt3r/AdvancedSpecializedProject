// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

class UCapsuleComponent;
class UCameraComponent;

UCLASS()
class DETECTIVE_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
#pragma region constructor
	// Sets default values for this pawn's properties
	APlayerPawn();
#pragma endregion

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
	UFUNCTION(BlueprintCallable, Category = "Player Movement")
	void Move(FVector2D _movement);

	UFUNCTION(BlueprintCallable, Category = "Player Movement")
	void Rotate(FVector2D _rotation);

	UFUNCTION(BlueprintCallable, Category = "Player Movement")
	void Interact();
#pragma endregion


protected:
#pragma region protected override function
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
#pragma endregion
};

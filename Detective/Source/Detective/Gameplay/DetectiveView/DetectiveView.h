// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DetectiveView.generated.h"

UCLASS()
class DETECTIVE_API ADetectiveView : public AActor
{
	GENERATED_BODY()

public:
#pragma region constructor
	// Sets default values for this actor's properties
	ADetectiveView();
#pragma endregion

#pragma region UPROPERTY
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Detective View")
	UStaticMeshComponent* Mesh = nullptr;
#pragma endregion

#pragma region public function
public:
	void ActivateShader();
#pragma endregion


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

#pragma once

#pragma region UE4 include
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"  
#pragma endregion

#pragma region game include
#include "DetectiveView.generated.h"  
#pragma endregion


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

private:
#pragma region private primitave Variable
	bool isActive = false;
	float Timer = 0.0f;
#pragma endregion

};

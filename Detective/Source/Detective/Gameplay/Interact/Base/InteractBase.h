#pragma once

#pragma region UE4 include
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"  
#pragma endregion

#pragma region game include
#include "InteractBase.generated.h"  
#pragma endregion


UCLASS()
class DETECTIVE_API AInteractBase : public AActor
{
	GENERATED_BODY()

public:
#pragma region constructor
	// Sets default values for this actor's properties
	AInteractBase();
#pragma endregion

public:
#pragma region public override function
	// Called every frame
	virtual void Tick(float DeltaTime) override;
#pragma endregion

#pragma region UFUNCTION
	UFUNCTION(BlueprintNativeEvent, Category = "Interact Base")
	void Interact(AActor* OtherActor);
#pragma endregion


protected:
#pragma region protected override function
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
#pragma endregion



};

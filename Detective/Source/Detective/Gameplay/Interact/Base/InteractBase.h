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
	// Sets default values for this actor's properties
	AInteractBase();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


};

#pragma once

#pragma region UE4 include
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"  
#pragma endregion


#pragma region projcet unclude
#include "Moveable.generated.h"  
#pragma endregion


UCLASS()
class DETECTIVE_API AMoveable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMoveable();

	UStaticMeshComponent* Mesh = nullptr;

	bool Move(FVector _movement);
};

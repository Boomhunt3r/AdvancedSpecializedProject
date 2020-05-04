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
#pragma region constructor
	// Sets default values for this actor's properties
	AMoveable();
#pragma endregion


#pragma region UPROPERTY
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Moveable")
	UStaticMeshComponent* Mesh = nullptr;
#pragma endregion


#pragma region public function
	bool Move(FVector _movement);
#pragma endregion

};

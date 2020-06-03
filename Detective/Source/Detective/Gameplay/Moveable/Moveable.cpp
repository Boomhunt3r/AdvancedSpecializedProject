#pragma region project include
#include "Moveable.h"  
#pragma endregion


#pragma region UE4 include
#include "Components/StaticMeshComponent.h"  
#pragma endregion


// Sets default values
AMoveable::AMoveable()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	USceneComponent* pRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = pRoot;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(pRoot);

	Tags.Add("Moveable");

}

bool AMoveable::Move(FVector _movement)
{
	FHitResult hit;
	Mesh->AddWorldOffset(_movement, true, &hit);

	return !hit.bBlockingHit;
}

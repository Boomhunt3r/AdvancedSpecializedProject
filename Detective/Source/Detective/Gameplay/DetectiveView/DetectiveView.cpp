#pragma region project include
#include "DetectiveView.h"  
#pragma endregion

#pragma region UE4 include
#include "Components/StaticMeshComponent.h"  
#pragma endregion


// Sets default values
ADetectiveView::ADetectiveView()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	USceneComponent* pRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = pRoot;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(pRoot);

	Tags.Add("View");

}

void ADetectiveView::ActivateShader()
{
	AActor::Destroy();
}

// Called when the game starts or when spawned
void ADetectiveView::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ADetectiveView::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


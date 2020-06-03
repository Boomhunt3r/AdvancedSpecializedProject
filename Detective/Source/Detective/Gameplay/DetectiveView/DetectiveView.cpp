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
	PrimaryActorTick.bCanEverTick = true;
	
	USceneComponent* pRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = pRoot;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(pRoot);

	Tags.Add("View");

}

void ADetectiveView::ActivateShader()
{
	Mesh->SetRenderCustomDepth(true);
	Mesh->SetCustomDepthStencilValue(2.0f);

	isActive = true;
}

// Called when the game starts or when spawned
void ADetectiveView::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ADetectiveView::Tick(float DeltaTime)
{
	if (isActive == true)
	{
		Timer += DeltaTime;
	}

	if (Timer >= 2.5f)
	{
		Mesh->SetRenderCustomDepth(false);
		Mesh->SetCustomDepthStencilValue(0.0f);

		isActive = false;
		Timer = 0.0f;
	}

	Super::Tick(DeltaTime);
}


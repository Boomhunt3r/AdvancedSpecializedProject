#pragma once

#pragma region UE4 include
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"  
#pragma endregion

#pragma region project include
#include "PlayerAnimation.generated.h"  
#pragma endregion

UCLASS()
class DETECTIVE_API UPlayerAnimation : public UAnimInstance
{
	GENERATED_BODY()

public:
#pragma region UPROPERTY
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerAnimation")
	bool IsIdle = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerAnimation")
	bool IsRun = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerAnimation")
	bool IsWalk = false;
#pragma endregion


};

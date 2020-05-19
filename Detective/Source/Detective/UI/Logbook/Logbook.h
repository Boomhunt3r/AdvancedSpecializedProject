#pragma once

#pragma region UE4 include
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"  
#pragma endregion

#pragma region project include
#include "Logbook.generated.h"  
#pragma endregion

UCLASS()
class DETECTIVE_API ULogbook : public UUserWidget
{
	GENERATED_BODY()

public:
#pragma region UFUNCTION
	UFUNCTION(BlueprintImplementableEvent, Category = "Logbook")
	void UpdateEntries();

	UFUNCTION(BlueprintCallable, Category = "Logbook")
	TMap<int, FString> GetAllEntries();
#pragma endregion

#pragma region public function
	void AddEntry(int _id, FString _text);
#pragma endregion

private:
#pragma region private variable
	TMap<int, FString> m_entries;
#pragma endregion

};

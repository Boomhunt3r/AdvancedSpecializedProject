#pragma once

#pragma region UE4 include
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h" 
#include "Components/Image.h"
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

	UFUNCTION(BlueprintCallable, Category = "Logbook")
	TMap<int, UTexture2D*> GetAllImageEntries();

	UFUNCTION(BlueprintCallable, Category = "Logbook")
	TMap<int, UTexture2D*> GetAllClearEntries();
#pragma endregion

#pragma region public function
	void AddEntry(int _id, FString _text);

	void AddEntry(int _id, UTexture2D* _image);

	void AddClearEntry(int _id, UTexture2D* _image);
#pragma endregion

private:
#pragma region private variable
	TMap<int, FString> m_entries;
	TMap<int, UTexture2D*> m_Entriess;
	TMap<int, UTexture2D*> m_Clear;
#pragma endregion

};

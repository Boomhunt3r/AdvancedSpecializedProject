#include "Logbook.h"

#pragma region UFUNCTION
TMap<int, FString> ULogbook::GetAllEntries()
{
	return m_entries;
}

TMap<int, UTexture2D*> ULogbook::GetAllImageEntries()
{
	return m_Entriess;
}

TMap<int, UTexture2D*> ULogbook::GetAllClearEntries()
{
	return m_Clear;
}
#pragma endregion


#pragma region public function
void ULogbook::AddEntry(int _id, FString _text)
{
	if (!m_entries.Find(_id))
		m_entries.Add(_id, _text);
}

void ULogbook::AddEntry(int _id, UTexture2D* _image)
{
	if (!m_Entriess.Find(_id))
		m_Entriess.Add(_id, _image);
}

void ULogbook::AddClearEntry(int _ID, UTexture2D* _Image)
{
	if (!m_Clear.Find(_ID))
		m_Clear.Add(_ID, _Image);
}
#pragma endregion

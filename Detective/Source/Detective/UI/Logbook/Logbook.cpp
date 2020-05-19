#include "Logbook.h"

#pragma region UFUNCTION
TMap<int, FString> ULogbook::GetAllEntries()
{
	return m_entries;
}
#pragma endregion

#pragma region public function
void ULogbook::AddEntry(int _id, FString _text)
{
	if (!m_entries.Find(_id))
		m_entries.Add(_id, _text);
}
#pragma endregion

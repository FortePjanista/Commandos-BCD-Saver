#include "saveFile.h"

template <int Size>
template <int ... Ids>
struct SaveFileArray<Size>::SaveFileArrayInternal
{
	SaveFileArrayInternal() : saveFiles{ SaveFile(Ids, "Empty")... } {}

	SaveFile saveFiles[Size];
};

template <int Size>
template <int _Size, int ... _Ids>
struct SaveFileArray<Size>::SaveFileArrayHelper : public SaveFileArray<Size>::SaveFileArrayHelper<_Size - 1, _Size - 1, _Ids...>
{};

template <int Size>
template <int ... _Ids>
struct SaveFileArray<Size>::SaveFileArrayHelper<0, _Ids...>
{
	using type = SaveFileArrayInternal<_Ids...>;
};

template <int Size>
constexpr SaveFile & SaveFileArray<Size>::operator[](int id)
{
	return saves.saveFiles[id];
}
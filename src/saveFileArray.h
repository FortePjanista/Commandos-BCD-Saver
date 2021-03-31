#ifndef SAVE_FILE_ARRAY_H
#define SAVE_FILE_ARRAY_H

class SaveFile;

// The folliwing struct allows to create instantly initialized array
// of SaveFile objects with sequence of their IDs from 0 to Size-1
// calculated at compile time
template <int Size>
struct SaveFileArray
{
private:

	// It contains the physical SaveFile array
	template <int ... Ids>
	struct SaveFileArrayInternal;

	// A helper structure used in computing values using recursion
	template <int _Size, int ... _Ids>
	struct SaveFileArrayHelper;

	// It is structure that contains a final type to return
	template <int ... _Ids>
	struct SaveFileArrayHelper<0, _Ids...>;

	template <int _Size>
	using InitSaveFileArray = typename SaveFileArrayHelper<_Size>::type;

	InitSaveFileArray<Size> saves;

public:
	constexpr SaveFile & operator[](int id);
};

#include "saveFileArray.tpp"

#endif // SAVE_FILE_ARRAY_H
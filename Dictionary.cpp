#include "Dictionary.h"

void Dictionary::createArr(int*& const arr, const int& length)
{
	arr = new int[length];
}

void Dictionary::fillArr(int*& const arr, const int& value, const int& length)
{
	arr[length] = value;
}

void Dictionary::copyArr(int*& const arr, int*& const arr2, const int& length)
{
	for (size_t i = 0; i < length; i++)
	{
		arr[i] = arr2[i];
	}
}

void Dictionary::cleanArr(int*& const arr) 
{
	delete[] arr;
	arr = nullptr;
}

void Dictionary::createDict(int*& const arrValue, const int& value, const int& length)
{
	createArr(arrValue, length+1);
	fillArr(arrValue, value, length);
}

void Dictionary::fillDict(int*& const arrValue, const int& value, const int& length)
{
	int* arrTemp = nullptr;
	createArr(arrTemp, length);
	copyArr(arrTemp, arrValue, length);
	cleanArr(arrValue);

	createArr(arrValue, length+1);
	copyArr(arrValue, arrTemp, length);
	fillArr(arrValue, value, length);
	cleanArr(arrTemp);
}
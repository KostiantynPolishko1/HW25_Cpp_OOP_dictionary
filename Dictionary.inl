#ifndef DICT_INL
#define DICT_INL

#include "Dictionary.h"

template<typename T1, typename T2>
inline bool Dictionary<T1, T2>::isKey(const T1& key, short& searchIndex) {
	for (short i = 0; i < this->length; i++)
		if (key == this->arrKey[i])
		{
			searchIndex = i;
			return true;
		}
	return false;
}

template<typename T1, typename T2>
inline void Dictionary<T1, T2>::createArr(T1*& const arrKey, T2*& const arrValue, const int& length, const bool& flag)
{
	if (flag)
		arrKey = new T1[length];
	else
		arrValue = new T2[length];
}

template <typename T1, typename T2>
inline void Dictionary<T1, T2>::fillArr(T1*& const arrKey, T2*& const arrValue, const bool& flag)
{
	flag ? arrKey[this->length] = this->key : arrValue[this->length] = this->value;
}

template<typename T1, typename T2>
inline void Dictionary<T1, T2>::copyArr(T1*& const arrKey1, T1*& const arrKey2, T2*& const arrValue1, T2*& const arrValue2, const bool& flag, const bool& isKey, const short& searchIndex)
{
	for (size_t i = 0, j = 0; j < this->length; i++, j++) {
		if (isKey && j == searchIndex) {
			i--;
			continue;
		}
		if (flag)
			arrKey1[i] = arrKey2[j];
		else
			arrValue1[i] = arrValue2[j];
	}
	
	/*if (flag) {
		for (size_t i = 0; i < this->length; i++) {
			if (isKey && i == searchIndex)
				continue;
			arrKey1[i] = arrKey2[i];
		}
	}
	else {
		for (size_t i = 0; i < this->length; i++) {
			if (isKey && i == searchIndex)
				continue;
			arrValue1[i] = arrValue2[i];
		}
	}*/
}

template <typename T1, typename T2>
inline void Dictionary<T1, T2>::cleanArr(T1*& const arr1, T2*& const arr2, const bool& flag)
{
	if (flag) {
		delete[] arr1;
		arr1 = nullptr;
	}
	else {
		delete[] arr2;
		arr2 = nullptr;
	}
}

template<typename T1, typename T2>
inline void Dictionary<T1, T2>::createDict(T1*& const arrKey, T2*& const arrValue, const bool& flag)
{
	createArr(arrKey, arrValue, this->length+1, flag);
	fillArr(arrKey, arrValue, flag);
}

template<typename T1, typename T2>
inline void Dictionary<T1, T2>::extendDict(T1*& const arrKey, T2*& const arrValue, const bool& flag)
{
	T1* arrTempKey{};
	T2* arrTempValue{};
	createArr(arrTempKey, arrTempValue, this->length, flag);
	copyArr(arrTempKey, this->arrKey, arrTempValue, this->arrValue, flag);
	cleanArr(this->arrKey, this->arrValue, flag);

	createArr(this->arrKey, this->arrValue, this->length + 1, flag);
	copyArr(this->arrKey, arrTempKey, this->arrValue, arrTempValue, flag);
	fillArr(this->arrKey, this->arrValue, flag);
	cleanArr(arrTempKey, arrTempValue, flag);
}

template<typename T1, typename T2>
inline void Dictionary<T1, T2>::reduceDict(const short& searchInex, const bool& flag) 
{
	T1* arrTempKey{};
	T2* arrTempValue{};

	createArr(arrTempKey, arrTempValue, this->length, flag);
	copyArr(arrTempKey, this->arrKey, arrTempValue, this->arrValue, flag);
	cleanArr(this->arrKey, this->arrValue, flag);

	createArr(this->arrKey, this->arrValue, this->length-1, flag);
	copyArr(this->arrKey, arrTempKey, this->arrValue, arrTempValue, flag, true, searchInex);
	cleanArr(arrTempKey, arrTempValue, flag);
}

template<typename T1, typename T2>
inline void Dictionary<T1, T2>::append(const T1& key, const T2& value)
{
	setKey(key);
	setValue(value);

	if (this->length == 0)
	{
		createDict(this->arrKey, this->arrValue, true);	//array of keys
		createDict(this->arrKey, this->arrValue, false);	//array of values
	}
	else
	{
		extendDict(this->arrKey, this->arrValue, true);	//array of keys
		extendDict(this->arrKey, this->arrValue, false);	//array of values
	}
	this->length++;
}

template<typename T1, typename T2>
inline void Dictionary<T1, T2>::remove(const T1& key) {

	short searchIndex{};
	if (this->length == 0 || !isKey(key, searchIndex))
		return;

	reduceDict(searchIndex, true);	//array of keys
	reduceDict(searchIndex, false);	//array of values

	this->length--;
}

template<typename T1, typename T2>
inline void Dictionary<T1, T2>::append(const T1& key) {
	T2 value{};
	append(key, value);
}

template <typename T1, typename T2>
inline T1* Dictionary<T1, T2>::getKey() const {
	return this->arrKey;
}

template <typename T1, typename T2>
inline T2* Dictionary<T1, T2>::getValue() const {
	return this->arrValue;
}

template <typename T1, typename T2>
inline int Dictionary<T1, T2>::getLength() const {
	return this->length;
}

template <typename T1, typename T2>
inline void Dictionary<T1, T2>::setKey(const T1& key) {
	this->key = key;
}

template <typename T1, typename T2>
inline void Dictionary<T1, T2>::setValue(const T2& value) {
	this->value = value;
}

#endif
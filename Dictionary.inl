#ifndef DICT_INL
#define DICT_INL

#include "Dictionary.h"

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
inline void Dictionary<T1, T2>::copyArr(T1*& const arrKey1, T1*& const arrKey2, T2*& const arrValue1, T2*& const arrValue2, const bool& flag)
{
	if (flag) {
		for (size_t i = 0; i < this->length; i++)
			arrKey1[i] = arrKey2[i];
	}
	else {
		for (size_t i = 0; i < this->length; i++)
			arrValue1[i] = arrValue2[i];
	}
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
inline void Dictionary<T1, T2>::createDict(T1*& const arrKey, T2*& const arrValue, const int& length, const bool& flag)
{
	createArr(arrKey, arrValue, length, flag);
	fillArr(arrKey, arrValue, flag);
}

template<typename T1, typename T2>
inline void Dictionary<T1, T2>::extendDict(T1*& const arrKey, T2*& const arrValue, const int& length, const bool& flag)
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
inline void Dictionary<T1, T2>::append(const T1& key, const T2& value)
{
	setKey(key);
	setValue(value);

	if (this->length == 0)
	{
		createDict(this->arrKey, this->arrValue, this->length + 1, true);	//array of keys
		createDict(this->arrKey, this->arrValue, this->length + 1, false);	//array of values
	}
	else
	{
		extendDict(this->arrKey, this->arrValue, this->length + 1, true);	//array of keys
		extendDict(this->arrKey, this->arrValue, this->length + 1, false);	//array of values
	}
	this->length++;
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
inline void Dictionary<T1, T2>::setKey(const T1& key) {
	this->key = key;
}

template <typename T1, typename T2>
inline void Dictionary<T1, T2>::setValue(const T2& value) {
	this->value = value;
}

#endif
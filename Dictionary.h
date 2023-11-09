#pragma once

#ifndef DICTIONARY_H
#define DICTIONARY_H

template <typename T1, typename T2>
class Dictionary
{
private:
	T1 key;
	T2 value;

	T1* arrKey;
	T2* arrValue;

	int length;

#pragma region methods
	void createArr(T1*& const, T2*& const, const int&, const bool&);

	void fillArr(T1*& const, T2*& const, const bool&);

	void copyArr(T1*& const, T1*& const, T2*& const, T2*& const, const bool&);

	void cleanArr(T1*& const, T2*& const, const bool&);

	void createDict(T1*& const, T2*& const, const int&, const bool&);

	void extendDict(T1*& const, T2*& const, const int&, const bool&);

#pragma endregion methods

#pragma region setters
	void setKey(const T1& key);
	void setValue(const T2& key);
#pragma endregion setters

public:
	Dictionary() : arrKey{}, arrValue{}, key{}, value{}, length{} {}

	~Dictionary()
	{
		cleanArr(this->arrKey, this->arrValue, true);	//array of keys
		cleanArr(this->arrKey, this->arrValue, false);	//array of values
	}

	void append(const T1& key, const T2& value)
	{
		setKey(key);
		setValue(value);

		if (this->length == 0)
		{
			createDict(this->arrKey, this->arrValue, this->length + 1, true);	//array of keys
			createDict(this->arrKey, this->arrValue, this->length + 1, false);//array of values
		}
		else
		{
			extendDict(this->arrKey, this->arrValue, this->length + 1, true);	//array of keys
			extendDict(this->arrKey, this->arrValue, this->length + 1, false);	//array of values
		}
		this->length++;
	}

#pragma region getters
	T1* getKey() const;

	T2* getValue() const;
#pragma endregion getters

};

#include "Dictionary.inl"

#endif DICTIONARY_H
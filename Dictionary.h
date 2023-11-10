#pragma once

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>

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

	void copyArr(T1*& const, T1*& const, T2*& const, T2*& const, const bool&, const bool& isKey = false, const short& searchIndex = 0);

	void cleanArr(T1*& const, T2*& const, const bool&);

	void createDict(T1*& const, T2*& const, const bool&);

	void extendDict(T1*& const, T2*& const, const bool&);

	void reduceDict(const short&, const bool&);

	bool isKey(const T1&, short&);

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

	void append(const T1&, const T2&);

	void append(const T1&);

	void remove(const T1&);

	void pop();

	void keys(T1*& const);

	void values(T2*& const);

	const T2& operator[](const T1&) const;

	T2& operator[](const T1& indexKey);

	friend std::ostream& operator<<(std::ostream& out, const Dictionary<T1, T2>& dict)	{
		static short index{ -1 };
		index++;
		return out << " key: " << dict.getKey()[index] << " | value: " << dict.getValue()[index];
	}

#pragma region getters
	T1* getKey() const;

	T2* getValue() const;

	int getLength() const;
#pragma endregion getters

};

#include "Dictionary.inl"

#endif DICTIONARY_H
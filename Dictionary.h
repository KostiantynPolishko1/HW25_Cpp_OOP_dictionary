#pragma once

#ifndef DICTIONARY_H
#define DICTIONARY_H

class Dictionary
{
private:
	int length;
	int* arrKey;
	int* arrValue;

	void createArr(int*& const, const int&);

	void fillArr(int*& const, const int&, const int&);

	void copyArr(int*& const, int*& const, const int&);

	void cleanArr(int*& const);

	void createDict(int*& const, const int&, const int&);

	void fillDict(int*& const, const int&, const int&);

public:
	Dictionary() : length{}, arrKey{}, arrValue{} {
	}

	~Dictionary() 
	{
		cleanArr(this->arrKey);
	}

	void append(const int& key, const int& value) 
	{
		if (this->length == 0) {
			createDict(this->arrKey, key, this->length);
			createDict(this->arrValue, value, this->length);
		}
		else
		{
			fillDict(this->arrKey, key, this->length);
			fillDict(this->arrValue, value, this->length);
		}
		this->length++;
	}

	int* getKey() {
		return this->arrKey;
	}

	int* getValue() {
		return this->arrValue;
	}
};
#endif
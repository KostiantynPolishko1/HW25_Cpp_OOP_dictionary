#pragma once

#ifndef OUTPUT_H
#define OUTPUT_H

#include "Dictionary.h"

template <typename T>
void printDict(const T* arr, const short& length) 
{
	std::cout << std::endl;
	for (short i = 0; i < length; i++)
		std::cout << arr[i] << "\n";
}

#endif // !OUTPUT_H

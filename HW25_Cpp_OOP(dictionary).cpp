#include <iostream>
#include "Dictionary.h"

int main()
{
	int length{};
    Dictionary<float, bool> dict;

	dict.append(1.1f, true);
	dict.append(2.2f, false);
	dict.append(3.3f);

	length = dict.getLength();
	float* arr{};
	dict.keys(arr);
	for (short i = 0; i < length; i++)
		std::cout << arr[i] << "\t";
	std::cout << std::endl;
	delete[] arr;
	arr = nullptr;

	for (short i = 0; i < length; i++)
		std::cout << dict.getKey()[i] << "\t| " << dict.getValue()[i] << "\n";

	dict.remove(2.2f);

	length = dict.getLength();
	for (short i = 0; i < length; i++)
		std::cout << dict.getKey()[i] << "\t| " << dict.getValue()[i] << "\n";

	dict.pop();

	length = dict.getLength();
	for (short i = 0; i < length; i++)
		std::cout << dict.getKey()[i] << "\t| " << dict.getValue()[i] << "\n";

    return 0;
}
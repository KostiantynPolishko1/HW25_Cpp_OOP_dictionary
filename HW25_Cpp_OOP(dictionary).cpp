#include <iostream>
#include "Dictionary.h"

int main()
{
	int length{};
    Dictionary<float, char> dict;

	dict.append(1.1f, 'a');
	dict.append(2.2f, 'b');
	dict.append(3.3f);

	/*length = dict.getLength();
	float* arrKeys{};
	dict.keys(arrKeys);
	for (short i = 0; i < length; i++)
		std::cout << arrKeys[i] << "\t";
	std::cout << std::endl;
	delete[] arrKeys;
	arrKeys = nullptr;

	char* arrValues{};
	dict.values(arrValues);
	for (short i = 0; i < length; i++)
		std::cout << arrValues[i] << "\t";
	std::cout << std::endl;
	delete[] arrValues;
	arrValues = nullptr;

	for (short i = 0; i < length; i++)
		std::cout << dict.getKey()[i] << "\t| " << dict.getValue()[i] << "\n";

	dict.remove(2.2f);

	length = dict.getLength();
	for (short i = 0; i < length; i++)
		std::cout << dict.getKey()[i] << "\t| " << dict.getValue()[i] << "\n";

	dict.pop();
*/

	char temp = dict[2.3f];
	std::cout << temp << "\n";

	dict[2.3f] = 'f';

	length = dict.getLength();
	for (short i = 0; i < length; i++)
		std::cout << dict.getKey()[i] << "\t| " << dict.getValue()[i] << "\n";

    return 0;
}

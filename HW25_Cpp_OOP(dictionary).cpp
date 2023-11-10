#include "Dictionary.h"
#include "OutPut.h"

int main()
{
	int length{};
    Dictionary<float, char> dict;

	dict.append(1.1f, 'a');	//add key + value
	dict.append(2.2f, 'b');	//add key + value
	dict.append(3.3f);		//add key + none

	std::cout << dict << "\n";	//print data of dict by ostream << object

	float* arrKeys{};
	dict.keys(arrKeys);	//array of keys by deep copy

	printDict(arrKeys, dict.getLength());
	delete[] arrKeys;
	arrKeys = nullptr;

	char* arrValues{};
	dict.values(arrValues);	//array of values by deep copy

	printDict(arrValues, dict.getLength());
	delete[] arrValues;
	arrValues = nullptr;

	dict.remove(2.2f);	//delete item(key + value) by index key

	dict.pop();	//delete the last item(key + value)

	dict[2.4f] = 'f';	//add new value by index operator[key]

	std::cout << dict[2.4f] << "\n"; //take the value be index operator[key]

	std::cout << dict << "\n";	//print data of dict by ostream << object

    return 0;
}

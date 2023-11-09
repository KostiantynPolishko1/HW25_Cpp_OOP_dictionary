#include <iostream>
#include "Dictionary.h"

int main()
{
    Dictionary<float, bool> dict;
	dict.append(1.1f, true);
	dict.append(2.2f, false);
	dict.append(3.3f, true);

	std::cout << dict.getKey()[0] << "\t| " << dict.getValue()[0] << "\n";
	std::cout << dict.getKey()[1] << "\t| " << dict.getValue()[1] << "\n";
	std::cout << dict.getKey()[2] << "\t| " << dict.getValue()[2] << "\n";

    return 0;
}
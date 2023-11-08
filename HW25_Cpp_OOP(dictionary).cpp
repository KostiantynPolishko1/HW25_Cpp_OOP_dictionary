#include <iostream>
#include "Dictionary.h"

int main()
{
    Dictionary dict;
    dict.append(1, 2);
    dict.append(2, 3);

    std::cout << "\n\tkey: " << dict.getKey()[0] << "\tvalue: " << dict.getValue()[0];
    std::cout << "\n\tkey: " << dict.getKey()[1] << "\tvalue: " << dict.getValue()[1];

    return 0;
}
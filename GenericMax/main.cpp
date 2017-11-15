#include <iostream>

template <typename T>
T Max(T first, T sconde, T three)
{
	return first > sconde ? (first > three ? first : three) : (sconde > three ? sconde : three);
}

void main(void)
{
	std::cout << "Int: " << Max<int>(1, 3, 2) << std::endl;
	std::cout << "Double: " << Max<double>(1.1, 2.2, 3.3) << std::endl;
}
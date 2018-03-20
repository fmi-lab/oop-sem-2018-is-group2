#include <iostream>
#include "IntContainer.h"
bool isThree(int&elem) {
	return elem == 3;
}
bool isEven(int& elem) {
	return elem % 2 == 0;
}
int main()
{
	IntArrayContainer cont1;
	cont1.add(1);
	cont1.add(2);
	cont1.add(3);
	cont1.add(4);
	cont1.add(5);
	cont1.print();
	std::cout <<"count:"<< cont1.count() << '\n';
	std::cout <<"empty:"<< cont1.empty() << '\n';
	std::cout <<"full:"<< cont1.full() << '\n';
	std::cout <<"member:"<< cont1.member(12) << '\n';
	cont1.remove(3);
	std::cout << "count:" << cont1.count() << '\n';
	cont1.print();
	//std::cout << "find:" << cont1.find(isThree) << '\n';
	/*const*/ IntArrayContainer res = cont1.filter(isEven);
	res.print();
	res.map([](int& elem)->void {elem++; });
	res.print();
	res[0] = 21;
	std::cout << res[0];
	return 0;
}

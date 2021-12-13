#include <iostream>

#include "../Zadanie_8/a.h"

const A copy(const A& a) {
	A a1(a);
	return a;
}

const A copy(A&& a) {
	A a1 = std::move(a);
	return a1;
}

int main()
{
	std::string st = "TestTEST";

	A a1(st);
	std::cout << a1.get() << std::endl;
	A a2=copy(a1);
	std::cout << a2.get() << std::endl;
	A a3 = copy(A("ABECADLO"));
	std::cout << a3.get() << std::endl;
	

	return 0;
}
#include<iostream>

#include "../Zadanie_8/a.h"

template <typename T>
const A copy(T&& a) {
	if (std::is_rvalue_reference<decltype(a)>::value)
	{
		A a1= std::move(a);
		return a1;
	}
	else
	{
		A a1(a);
		return a1;
	}
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

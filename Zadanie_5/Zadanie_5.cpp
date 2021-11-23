#include <iostream>
using namespace std;

template <typename T1, typename T2>
auto add1(T1 a, T2 b)
{
	return a + b;
}

template<typename T1, typename T2>
auto add1(T1 *a, T2 *b)
{
	cout << "Wywolanie funkcji ze wskaznikami: " << endl;
	return *a + *b;
}

template<>
auto add1(const char* a, const char* b)
{
	cout << "Wywołanie funkcji z const char*: " << endl;
	string ss;
	ss += a;
	ss += b;
	return ss;
}
template <typename T3, typename T4, typename T5>
auto add2(T3 a, T4 b, T5 f)
{
	return f(a, b);
}

int main()
{
	string x = "XX";
	string y = "YY";

	cout << add1(3.0, 2.19) << endl;
	cout << add1(5, 5) << endl;
	cout << add1(10, 2.5) << endl;
	cout << add1(x, y) << endl;

	int new1 = 28;
	double new2 = 32.13;
	int* ptr = &new1;
	double* ptr2 = &new2;
	cout << add1(ptr, ptr2) << endl;

	const char* new3 = "abc";
	const char* new4 = "ABC";
	cout << add1(new3, new4) << endl;
	//auto fun = [](auto a, auto b) {return a + b; };
	//cout << add2(5, 8, fun) << endl;
	//cout << add2(4.75, 8.25, ([](auto a, auto b) {return a + b; })) << endl;
	//cout << add2(4, 8.25, ([](auto a, auto b) {return a + b; })) << endl;
	//cout << add2(x, y, ([](auto a, auto b) {return a + b; })) << endl;
}

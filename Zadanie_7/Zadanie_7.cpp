#include <iostream>
using namespace std;

template <typename ...Args>
auto add(Args ...args)
{
	return (0.0 + ... + args);
}

int main()
{
	cout << add(1, 2.13f, 2.11,0.00001,3)<< endl;

}

#include <iostream>
#include <string>


//variadic template
//fold expression operacja wykonywana na wielu argumentach


template<typename... Args>
double sum(Args ... args);

std::string  add1(const char* a1, const char* a2);
int main()
{
    std::cout << sum(12, 65, 97, 23, 12.4, 43.865);
}

template<typename... Args>
double sum(Args ... args)
{
    return (args + ... );
}

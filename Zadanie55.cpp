#include <iostream>
#include <string>



template<class T1, class T2>
auto add1(T1 const *a1, T2 const *a2) ->decltype(*a1 + *a2)
{
    return  *a1 + *a2;
}


int main()
{
    int a = 2;
    int b = 2;
    int* p = &a;
    int* s = &b;
    const char* k;
    const char* m;
    std::string i = "jeden ";
    std::string j = "dwa";
    std::cout << add1(p, s) << std::endl;
    std::cout << add1(&i, &j)<<std::endl;
    std::cout << add1(k, m)<<std::endl;
}



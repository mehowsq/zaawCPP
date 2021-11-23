#include <iostream>
#include "a.h"
//zadanie 9
/////////////////////////////////////////////////////

//A copy(const A& a);
//A copy(const A&& a);

//zadanie 10
/////////////////////////////////////////////////////
template <class T>
A copy(const T a);
int main()
{
    //zadanie od 8,9,10
    std::string sie = "ess";

    A obj(sie);
    std::cout << obj.get(); 
    A obj2(obj);
    std::cout << obj2.get();
    A obj3(std::move(obj));
    std::cout << obj3.get();

    A obj4 = copy(obj2);
    std::cout << obj4.get();


}

template<class T>
A copy(const A& a)
{
    return A(a);
}
A copy(const A&& a)
{
    return std::move(a);
}
template<class T>
A copy(const T a)
{
    return std::forward<T>(A(a));
}
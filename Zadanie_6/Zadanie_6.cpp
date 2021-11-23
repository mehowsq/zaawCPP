#include <iostream>
#include <cmath>
using namespace std;


template<typename T, typename U>
int add1(T const &a, U const &n)
{
    if (a < 0 or n < 0) {
        return -1;
    }
    else
        return pow( a, n );
}

int main() { 
    int a = -1, b = 2, c = 3, d = 4;
    
    cout << "     objętość hipersześcianu ->    " << a << "^" << b << "=" << add1(a, b) << endl;
    cout << "     objętość hipersześcianu ->    " << b << "^" << c << "=" << add1(b, c) << endl;
    cout << "     objętość hipersześcianu ->    " << c << "^" << d << "=" << add1(c, d) << endl;

    return 0;
}

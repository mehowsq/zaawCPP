#include <iostream>

using namespace std;


template<int length, int dim> struct hipervolume
{
    enum {v=length*hipervolume<length,dim-1>::v};
};


template<int length> struct hipervolume <length,0>
{
    enum {v=1};
};


template<int length> struct hipervolume<length, -1>
{
    enum{v=-1};
};


template<int dim> struct hipervolume <-1, dim>
{
    enum{v=-1};
};


template <> struct hipervolume<-1, -1>
{
    enum{v=-1};
};

int main()
{
    static_assert(hipervolume<5,5>::v == 3125);

    cout <<"6^3= ";
    
    cout << hipervolume<6,3>::v <<endl;
    
    cout << hipervolume<6,-1>::v <<endl;
    
    cout << hipervolume<-1,3>::v <<endl;
    
    cout << hipervolume<-1,1>::v <<endl;





}

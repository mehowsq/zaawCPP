#include "a.h"

A::~A()
{
	delete[] cha;
}

A::A(const std::string& str)
{
	std::size_t size = str.size() + 1;
	cha = new char[size];
	strcpy(cha, str.c_str());
}

A::A(const A& obj)
{
	cha = new char[sizeof(obj.get()) / sizeof(obj.get()[0])];
	strcpy(cha, obj.cha);
}

A::A(A&& obj)noexcept :
	cha{ obj.cha }

{
	obj.cha = nullptr;

}

char* A::get() const
{
	return cha;
}
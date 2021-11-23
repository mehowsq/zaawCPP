#pragma once
#include<string>
#include <iostream>
class A
{
private:
	char* cha;
public:
	~A();
	A(const std::string& str);
	A(const A& obj);
	A(A&& obj) noexcept;

public:
	char* get() const;
};
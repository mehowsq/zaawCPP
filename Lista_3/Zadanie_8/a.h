#pragma once

#include <string>
#include <iostream>
#include <cstring>

class A {
    private:
        size_t length{0};
        char* cha{nullptr};
    public:
        // WYWOLANIA KONSTURKTORA PRZYJMUJACEGO CONST REFERENCJE DO std::string
        A(const std::string& str) : length{str.length()}, cha{new char[length+1]} {
                std::cout<<"\nReferencja do std::string";
                str.copy(cha, length);
                cha[length] = '\0';
                std::cout << "\n" << cha << "\n";
            }
        // WYWOLANIE KONSTRUKTORA KOPIUJACEGO
        A(const A& obj) : length{obj.length}, cha{new char[length+1]} {
                std::memcpy(cha, obj.cha, length+1);
                std::cout << "\nWywolanie konstruktora kopiujacego\n";
                std::cout << "\nKopiuje " << cha << "\n";
            }
        // WYWOLANIE KONSTRUKTORA PRZENOSZACEGO
        A(A&& obj): length{obj.length}, cha{obj.cha} {
                std::cout << "\nWywolanie konstruktora przenoszacego\n";
                obj.cha = nullptr;
            }

        const char* get() const {
            return cha;
        }
        // WYWOLANIE DESTRUKTORA
        ~A() {
            delete[] cha;
        }
};



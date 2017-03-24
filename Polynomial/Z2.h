//Zbigniew Najder
#ifndef Z2_H
#define Z2_H

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <sstream>
using namespace std;

class Z2 {
	public:
		Z2();
		Z2(short int);
		operator short int();
		operator short int() const;
		Z2 & operator += (const Z2&);
		Z2 & operator *= (const Z2&);
		Z2 & operator /= (const Z2&);
	private:
		bool liczba;
		friend Z2 operator +(const Z2& liczba1, const Z2& liczba2);
		friend Z2 operator *(const Z2& liczba1, const Z2& liczba2);
		friend Z2 operator /(const Z2& liczba1, const Z2& liczba2);
		friend ostream & operator << (ostream & out,const Z2& liczba);
};

#endif

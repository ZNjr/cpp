//Zbigniew Najder
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "Z2.h"

class Polynomial {
	public:
		Polynomial();
		Polynomial(unsigned int,const Z2[]);
		Polynomial(unsigned int);
		Polynomial(const Polynomial&);
		~Polynomial();
		Z2 operator [](unsigned int index) const;
		Polynomial& operator +=(const Polynomial&);
		Polynomial& operator *=(const Polynomial&);
		Polynomial& operator = (const Polynomial&);
		string toString(string);
		unsigned int degree() const;
		void mnozenie(unsigned int);

	private:
		unsigned int stopien;
		unsigned char* wsp;
	private:
		
		void reduce();
		void setBit(unsigned int nO,unsigned char value);
		bool bitSet(unsigned int nO);
		bool bitSet(unsigned int nO) const;
		void dodaj(unsigned char* wspW2,unsigned int stopienW2);
		friend istream & operator >> (istream & in, Polynomial & w);
		friend ostream & operator << (ostream & out,const  Polynomial & w);
		friend Polynomial operator +(const Polynomial& liczba1, const Polynomial& liczba2);
		friend Polynomial operator *(const Polynomial& liczba1, const Polynomial& liczba2);
		friend Polynomial operator /(const Polynomial& liczba1, const Polynomial& liczba2); 
		friend Polynomial operator %(const Polynomial& liczba1, const Polynomial& liczba2);
		friend void mod(const Polynomial&, const Polynomial&, Polynomial&, Polynomial&);
};
#endif

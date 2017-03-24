//Zbigniew Najder
#include "Polynomial.h"
#define BITS_IN_CHAR 8

typedef unsigned long long int ull_int;
typedef unsigned char uchar;

string itostr(int i) {
	stringstream stream;
	stream << i;
	string string = stream.str();
	return string;
}

Polynomial::Polynomial() :
	stopien(0)
{
	this->wsp = (uchar*)calloc(1, sizeof(char));	
	setBit(0, 0);
}

Polynomial::Polynomial(unsigned int stopien, const Z2 wspolczynniki[]):
	stopien(stopien)
{
	int rozmiar = 1 + stopien / BITS_IN_CHAR;
	this->wsp = (uchar*)calloc(rozmiar, sizeof(char));
	for (unsigned int i = 0;i <= stopien;i++) {
		setBit(i, wspolczynniki[i]);
	}
	reduce();
}

Polynomial::Polynomial(unsigned int stopien) :
	stopien(stopien)
{
	this->wsp = (uchar*)calloc(1 + stopien / BITS_IN_CHAR, sizeof(char));
}

Polynomial::Polynomial(const Polynomial & w) :
	stopien(w.stopien)
{
	this->wsp = (uchar*)calloc(1 + w.stopien / BITS_IN_CHAR, sizeof(char));
	memcpy(wsp, w.wsp, 1 + w.stopien / BITS_IN_CHAR);
}

Polynomial::~Polynomial()
{
	free(wsp);
}

Z2 Polynomial::operator[](unsigned int index) const
{
	if(index<=stopien)
		return Z2(bitSet(index));
	else
		std::cout << "Niepoprawny indeks wielomianu\n";
		return Z2(bitSet(0));
}

Polynomial & Polynomial::operator+=(const Polynomial& w2)
{
	if (w2.stopien > stopien) {
		int rozmiar = stopien / BITS_IN_CHAR;
		int nowe = w2.stopien / BITS_IN_CHAR - rozmiar;
		
		if (nowe > 0) {
			wsp = (uchar*)realloc(wsp, 1 + w2.stopien / BITS_IN_CHAR);
			memset(wsp + rozmiar + 1, 0, nowe);
		}
		stopien = w2.stopien;
	}
	dodaj(w2.wsp, w2.stopien);
	reduce();
	return *this;
}

Polynomial & Polynomial::operator*=(const Polynomial & w2)
{
	*this = w2 * (*this);
 	 return *this;
}

Polynomial & Polynomial::operator=(const Polynomial & w)
{
	if (this == &w) return *this;
	free(wsp); 
	stopien = w.stopien;
	wsp = (uchar*)calloc(1 + stopien / BITS_IN_CHAR,sizeof(char));
	memcpy(wsp, w.wsp, 1 + stopien / BITS_IN_CHAR);
	return *this;
}

unsigned int Polynomial::degree() const
{
	return stopien;
}

void Polynomial::reduce(){
	while (bitSet(stopien) == 0 && stopien != 0) {
		stopien--;
	}
	wsp = (uchar*)realloc(wsp, 1 + stopien / BITS_IN_CHAR);
}

string Polynomial::toString(string xVar) 
{
	string string = "";
	for (unsigned int i = 0;i <=stopien;i++)
	{
		if (bitSet(i) != 0 || stopien == 0) {
			if(i==0) string += itostr(bitSet(i));
			if (i > 0) {
				string += xVar;
				string += "^" + itostr(i);
			}
			if (i < stopien) string += "+";
		}
	}
	return string;
}


Polynomial operator+(const Polynomial& w1, const Polynomial & w2)
{
	Polynomial wynik = w1;
	wynik += w2;
	return wynik;
}

Polynomial operator*(const Polynomial& w1, const Polynomial & w2)
{
	Polynomial wynik;
	if (w2.stopien != 0 && w1.stopien !=0) {
		free(wynik.wsp);
		wynik.stopien = w1.stopien + w2.stopien;
		wynik.wsp = (uchar*)calloc(1+(w1.stopien + w2.stopien)/BITS_IN_CHAR,sizeof(char));
		for (unsigned int i = 0;i <= w2.stopien;i++) {
			if (w2.bitSet(i)) {
				Polynomial tmpw1 = w1;
				tmpw1.mnozenie(i);
				wynik += tmpw1;
			}
		}
	}
	else if (w2.stopien == 0 && w2.bitSet(0)) wynik = w1;
	else if (w1.stopien == 0 && w1.bitSet(0)) wynik = w2;
	return wynik;
}

ostream & operator << (ostream & out, const Polynomial & w)
{
	out << "{";
	for (unsigned int i = 0;i < w.stopien;i++) {
		out << itostr(w.bitSet(i)) + ",";
	}
	out << itostr(w.bitSet(w.stopien)) + "}";
	return out;
}

istream & operator >> (istream & in, Polynomial & w)
{
	char ch = ' ';
	int stopien = -1;
	int rozmiar = 1;
	free(w.wsp);
	w.wsp = (uchar*)calloc(1,sizeof(char));
	while(ch!='{')
		in >> ch;
	while (1) {
			in >> ch;
			if (ch == '}')break;
			if (ch != ','&& ch!=' ') {
				unsigned int x = ch - '0';
				stopien++;
				if ((stopien + 1) / BITS_IN_CHAR >= rozmiar) {
					rozmiar++;
					w.wsp = (uchar*)realloc(w.wsp, rozmiar * sizeof(char));
					w.wsp[rozmiar-1] = 0;
				}
				w.setBit(stopien, x);
		}
	}
	if (stopien != -1) {
		w.stopien = stopien;
		w.reduce();
	}
	return in;
}

void mod(const Polynomial& u, const Polynomial& v, Polynomial& q, Polynomial& r)
{
	Polynomial wynik = u;
	if (v.stopien == 0 && !v.bitSet(0)) std::cout << "Dzielenie przez zero\n";
	else if (u.stopien < v.stopien) {
		r = u;
		q = Polynomial();
	}
	else{
		if (v.stopien != 0){
			if (v.stopien <= wynik.stopien){
				q.stopien = wynik.stopien - v.stopien;;
				free(q.wsp);
				q.wsp = (uchar*)calloc(1+(wynik.stopien - v.stopien)/BITS_IN_CHAR,sizeof(char));
				while (wynik.stopien >= v.stopien) {
					Polynomial tmp = v;
					q.setBit(wynik.stopien - v.stopien,1);
					tmp.mnozenie(wynik.stopien - v.stopien);
					wynik += tmp;
				}
			}
			r = wynik;
		}
		else {
			q = wynik;
			r = Polynomial();
		}
	}
}

Polynomial operator/(const Polynomial& w1, const Polynomial & w2)
{
	if (w2.stopien == 0 && w2.bitSet(0) == 0) {
		std::cout << "Dzielenie przez zero\n";
		return w1;
	}
		Polynomial q, r;
		mod(w1, w2, q, r);
		return q;
}

Polynomial operator%(const Polynomial& w1, const Polynomial & w2)
{
		Polynomial q, r;
		mod(w1, w2, q, r);
		return r;
}
bool Polynomial::bitSet(unsigned int numberOfBit) {
	unsigned int index = numberOfBit >> 3;
	unsigned char tmp = wsp[index];
	unsigned char bit = (tmp >> (numberOfBit & 7)) & 1;
	return (bit == 0) ? false : true;
}

bool Polynomial::bitSet(unsigned int numberOfBit) const{
	unsigned int index = numberOfBit >> 3;
	unsigned char tmp = wsp[index];
	unsigned char bit = (tmp >> (numberOfBit & 7)) & 1;
	return (bit == 0) ? false : true;
}

void Polynomial::setBit(unsigned int numberOfBit, unsigned char value){
	unsigned int index = numberOfBit >> 3;
	unsigned char tmp = wsp[index];
	tmp = tmp & ~(1 << (numberOfBit & 7)) | (value << (numberOfBit & 7));
	wsp[index] = tmp;
}

void Polynomial::dodaj(unsigned char* wspW2, unsigned int stopienW2)
{
	unsigned int rozmiar = 1 + stopienW2 / BITS_IN_CHAR;
	unsigned int ilosc64b = rozmiar / sizeof(long long int);
	unsigned int ilosc32b = rozmiar / sizeof(long int);
	unsigned int ilosc16b = rozmiar / sizeof(short int);
	unsigned int pozostale = rozmiar % sizeof(long long int);
	unsigned int sprawdzone = rozmiar - pozostale;

	if (ilosc64b > 0) {
		ull_int* w1 = (ull_int*)wsp;
		ull_int* w2 = (ull_int*)wspW2;

		for (int i = 0;i < ilosc64b;i++)
			w1[i] ^= w2[i];
		ilosc32b -= sizeof(long long int) / sizeof(long int) * ilosc64b;
		ilosc16b -= sizeof(long long int) / sizeof(short int) * ilosc64b;
	}

	if (ilosc32b > 0) {
		unsigned long int* w1 = (unsigned long int*)wsp;
		unsigned long int* w2 = (unsigned long int*)wspW2;

		for (int i = 0;i < ilosc32b;i++)
			w1[i + (sprawdzone) / sizeof(long int)] ^= w2[i + (sprawdzone) / sizeof(long int)];
		ilosc16b -= sizeof(long int) / sizeof(short int) * ilosc32b;
		pozostale = rozmiar % sizeof(long int);
		sprawdzone += ilosc32b * sizeof(long int);
	}
	if (ilosc16b > 0) {
		unsigned short int* w1 = (unsigned short int*)wsp;
		unsigned short int* w2 = (unsigned short int*)wspW2;

		for (int i = 0;i < ilosc16b;i++)
			w1[i + (sprawdzone) / sizeof(short int)] ^= w2[i + (sprawdzone) / sizeof(short int)];
		pozostale = rozmiar % sizeof(short int);
		sprawdzone += ilosc16b * sizeof(short int);
	}
	if (pozostale > 0) {
		for (int i = 0;i < pozostale;i++)
			wsp[i + sprawdzone] ^= wspW2[i + sprawdzone];
	}
}

void Polynomial::mnozenie(unsigned int przesuniecie){
	if(przesuniecie != 0) {
		unsigned int ilosc8b = przesuniecie >> 3;
		unsigned int pozostale = przesuniecie & 7;
		int rozmiar = 1 + (stopien) / BITS_IN_CHAR;
		int nowyRozmiar = 2 + (stopien + przesuniecie) / BITS_IN_CHAR;
		stopien = stopien + przesuniecie;
		unsigned char* tmp = (unsigned char*)calloc(nowyRozmiar, sizeof(char));

		if (ilosc8b > 0)
			for (int i = 0;i < rozmiar;i++)
				tmp[i + ilosc8b] = wsp[i];

		if (pozostale > 0) {
			int i = 0;
			int j = 0;
			tmp[i + ilosc8b] = wsp[i] << pozostale;
			i++;
			while (j < rozmiar - 1) {
				tmp[i + ilosc8b] = wsp[i] << pozostale | wsp[j] >> (BITS_IN_CHAR - pozostale);
				i++;
				j++;
			}
			tmp[j + 1 + ilosc8b] = wsp[j + 1] << pozostale | wsp[j] >> (BITS_IN_CHAR - pozostale);
		}
		wsp = (unsigned char*)realloc(wsp, nowyRozmiar * sizeof(char));
		memcpy(wsp, tmp, nowyRozmiar * sizeof(char));
		free(tmp);
	}
}

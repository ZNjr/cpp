
#include "Z2.h"

Z2::Z2():liczba(0) {}

Z2::Z2(short int liczba){
	this->liczba = liczba % 2 != 0;
}

Z2::operator short int() {
	return liczba;
}

Z2::operator short int() const
{
	return liczba;
}

Z2& Z2::operator+=(const Z2 & liczba)
{
	this->liczba = this->liczba ^ liczba.liczba;
	return *this;
}
Z2& Z2::operator*=(const Z2 & liczba)
{
	this->liczba = this->liczba & liczba.liczba;
	return *this;
}
Z2 & Z2::operator/=(const Z2 & liczba)
{
	if(liczba.liczba) this->liczba = this->liczba & liczba.liczba;
	else { cout << "Dzielenie przez zero\n"; }
	return *this;
}

ostream& operator<<(ostream & out, const Z2 & liczba)
{
	out << liczba.liczba;
	return out;
}

Z2 operator+(const Z2 & liczba1, const Z2 & liczba2)
{
	return Z2(liczba1.liczba ^ liczba2.liczba);
}

Z2 operator*(const Z2 & liczba1, const Z2 & liczba2)
{
	return Z2(liczba1.liczba & liczba2.liczba);
}


Z2 operator/(const Z2 & liczba1, const Z2 & liczba2)
{
	if (liczba2.liczba)
		return Z2(liczba1.liczba & liczba2.liczba);
	else{
		cout << "Dzielenie przez zero\n";
		return liczba1;
	}
}

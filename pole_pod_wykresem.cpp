#include <iostream>
#include <cmath>
using namespace std;
double a,b,c;

double wartosc_funkcji(double x){
	double wartosc = a*pow(x,2)+b*x+c;
	return wartosc;
}

int main(){
  double mini, maks, pole = 0;
  int ilosc_probek;
  
  cout << "podaj wspolczynniki funkcji kwadratowej"; 
  cout << endl << "a: "; cin >> a;
  cout << "b: "; cin >> b;
  cout << "c: "; cin >> c;
	 
  cout << "podaj zakres";	
  cout << endl << "od: "; cin >> mini; 
  cout << "do: "; cin >> maks;	
 
  cout << "dokladnosc" <<endl; cin >> ilosc_probek;
  
  double krok = (maks - mini)/ilosc_probek;
  	 
 for(double i = 0; i <= ilosc_probek; i ++ ){
 	mini += krok *i; 
 	double pole_prostokata = krok * wartosc_funkcji(mini);
 	pole += pole_prostokata;
 }
 cout << "pole pod wykresem wynosi: " << pole;
}

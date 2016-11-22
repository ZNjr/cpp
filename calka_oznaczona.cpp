#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

class Wielomian{
private:

public:	

int stopien;
float* wspolczynniki;
bool dodaj_nawiasy = false;

Wielomian(int stopien_wielomianu)
	{
     stopien = stopien_wielomianu;	 
  	 wspolczynniki = new float[stopien+1];
	 
   }
	
	void losowanie_wspolczynnikow(){
		for(int i=0;i<=stopien;i++){
			wspolczynniki[i]=(rand()%20)-10;	
		}
	}
     
    void wprowadz_wspolczynniki(){
    	for(int i=stopien;i>=0;i--){
		   cout << "x^" << i << ":";
		   cin >> wspolczynniki[i];
		  
		}
	} 
	
	void wypisz_wielomian()
	{
	   if(dodaj_nawiasy) cout << "(";
		for(int i=stopien;i>=0;i--)
		{    
			if(wspolczynniki[i]!=0){
	 			if(wspolczynniki[i]>0 && i !=stopien) cout << "+";
	 			if(wspolczynniki[i]!=1 && wspolczynniki[i]!=-1 || i==0 ) cout << wspolczynniki[i]; 
	 			if(i!=0) cout << "x";
				if(i>1) cout << "^" <<i;
			}
		}
		if(dodaj_nawiasy) cout << ")";
	}
	
	double wartosc_wielomianu(double x)
	{
		double suma = 0;	
		for(int i=stopien;i>=0;i--)
		{
			suma += wspolczynniki[i]*pow(x,i); 
		}
		return suma;
	}
	
	double calka_oznaczona(double poczatek, double koniec)
	{
			double pole = 0;	
	   for(int i=stopien;i>=0;i--)
		{
		
			pole += (wspolczynniki[i]*pow(koniec,i+1)/(i+1));
			pole -= (wspolczynniki[i]*pow(poczatek,i+1)/(i+1)); 
		}
			return pole;
	}
};

Wielomian mnozenie(Wielomian wielomian_1, Wielomian wielomian_2){
	Wielomian wielomian_wynikowy = Wielomian(wielomian_1.stopien+wielomian_2.stopien);
	for(int i=0;i<=wielomian_wynikowy.stopien;i++){
     wielomian_wynikowy.wspolczynniki[i] = 0;
	}
	for(int i=0;i<=wielomian_1.stopien;i++){
		for(int j=0;j<=wielomian_2.stopien;j++){
			wielomian_wynikowy.wspolczynniki[i+j] += wielomian_1.wspolczynniki[i]*wielomian_2.wspolczynniki[j];
		}
	}
	return wielomian_wynikowy;
}
  
  
int main(){
	srand(time(0));
	int st1,st2, st3;
	double x;

	cout << endl <<"Podaj stopien wielomianu 3: "; cin >> st3;

	Wielomian w_3 = Wielomian(st3);
		w_3.wprowadz_wspolczynniki();
		w_3.wypisz_wielomian();
   
   	double poczatek,koniec;
   	cout << endl << "Podaj poczatek przedzialu: "; cin >>poczatek;
   	cout << "Podaj koniec przedzialu: "; cin >> koniec;
	cout << "Calka oznaczona: " << w_3.calka_oznaczona(poczatek,koniec);
}





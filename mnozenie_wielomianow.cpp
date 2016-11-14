#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Wielomian{
private:

public:	
int stopien;
float* wspolczynniki;

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
     
void wypisz_wielomian(){
	
	for(int i=stopien;i>=0;i--){    
     if(wspolczynniki[i]>0 && i !=stopien) cout << "+";
	 if(wspolczynniki[i]>1 || wspolczynniki[i]<-1) {
	 cout << wspolczynniki[i]; 
	 if(i!=0) cout << "x";
	 if(i>1) cout << "^" <<i;
	}    
}

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
	int st1,st2;
	cout << "Podaje stopien wielomianu 1: ";
	cin >> st1;
	cout << "Podaj stopien wielomianu 2: ";
	cin >> st2;
	Wielomian w_1 = Wielomian(st1);
	w_1.losowanie_wspolczynnikow();
	cout << "(";
	w_1.wypisz_wielomian() ;
	cout << ")*(";
	Wielomian w_2 = Wielomian(st2);
	w_2.losowanie_wspolczynnikow();
	w_2.wypisz_wielomian();
	cout << ")=";
	
Wielomian wielomian_wynikowy = mnozenie(w_1,w_2);
wielomian_wynikowy.wypisz_wielomian();
}





#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Wektor{
	public:
	double x;
	double y;
	    Wektor(double x,double y):x(x),y(y){}
	
	void toString(){
		string punkt;
		punkt = '('+to_string(x)+','+to_string(y)+')'; 
		cout<<punkt;
		}
	};

class Lamana{
	private:
	vector <Wektor> tablica;
	public:
		void dodaj_na_koniec(Wektor w){
				tablica.push_back(w);
			}	
		double dlugosc(){
			double dlugosc = 0;
			for(unsigned int i=0; i<tablica.size()-1;i++){
				double odleglosc = sqrt(pow(tablica[i].x-tablica[i+1].x,2)+pow(tablica[i].y-tablica[i+1].y,2)); 
				dlugosc+=odleglosc;
				}
			return dlugosc;
			}
		bool czy_zamknieta(){
			return (tablica[0].x==tablica[tablica.size()-1].x && tablica[0].y==tablica[tablica.size()-1].y)?true:false;
			
			}
	
	};

int main(){
	Wektor w = Wektor(20.0,10.0);
	Wektor s = Wektor(20.0,100.0);
	Wektor k = Wektor(10.0,75.0);
	Lamana l;
	l.dodaj_na_koniec(w);
	l.dodaj_na_koniec(s);
	l.dodaj_na_koniec(k);
	cout<<l.dlugosc();
	}

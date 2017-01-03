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
	
	string toString(){
		string punkt;
		punkt = '('+to_string(x)+','+to_string(y)+')'; 
		return punkt;
		}
	};
	
	

class Lamana{
	private:
	vector <Wektor> tablica;
	public:
		void dodaj_na_koniec(Wektor& w){
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
		void przeson_o_wektor(Wektor w){
			for(unsigned int i=0;i<tablica.size();i++){
				tablica[i].x += w.x;
				tablica[i].y += w.y; 
			}
		}
		string toString(){
			 string lamana = "[";
				for(unsigned int i=0;i<tablica.size();i++){
					lamana+=tablica[i].toString();
					if(i!=tablica.size()-1) lamana += ",";
					}
			 lamana+="]";
			return lamana;
		}	
		void obroc(double alfa,Wektor& srodek){
			for(unsigned int i=0;i<tablica.size();i++){
				tablica[i].x= (tablica[i].x-srodek.x)*cos(alfa)-(tablica[i].y-srodek.y)*sin(alfa)+srodek.x;
				tablica[i].y= (tablica[i].x-srodek.x)*sin(alfa)-(tablica[i].y-srodek.y)*cos(alfa)+srodek.y;
			}
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
	cout<<l.toString()<<endl;
	l.przeson_o_wektor(Wektor(5.0,10.0));
	cout<<l.toString()<<endl;
	cout<<l.dlugosc();
	}

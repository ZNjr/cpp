#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <cmath>

using namespace std;

double promien, sx, sy;
double prostokat_maly[2][2];

bool czy_w_okregu(double point[2]){
	double wartosc = pow(point[0]-sx,2)+pow(point[1]-sy,2);
	return (wartosc <= pow(promien,2)) ? true : false;
}
bool czy_w_prostokacie_malym_x(double point[2]){
   return (point[0] >= prostokat_maly[0][0] && point[0] <= prostokat_maly[1][0]) ? true : false;
}

bool czy_w_prostokacie_malym_y(double point[2]){
   return (point[1] >= prostokat_maly[0][1] && point[1] <= prostokat_maly[1][1]) ? true : false; 
}

bool czy_w_czesci_wspolnej(double point[2]){
	return (czy_w_okregu(point) && czy_w_prostokacie_malym_y(point) && czy_w_prostokacie_malym_x(point)) ? true : false;
}

int main(){
	 
	    double prostokat_duzy[2][2], wylosowany_punkt[2];
	    double ilosc_prob;
		double punkty_trafione = 0, pole_prostokata;
		
		cout << "podaj wspolzedne srodka okrego" << endl << "x:"; cin >> sx;
		cout << "podaj wspolzedne srodka okrego" << endl << ":y"; cin >> sy;
		cout << "podaj promien okrego" << endl; cin >> promien;
	    cout << "Podaj x i y przeciwleglych wierzcholkow prostokata" << endl <<"x1:"; cin >> prostokat_maly[0][0];
		cout << "y1:"; cin >> prostokat_maly[0][1];
    	cout << "x2:"; cin >> prostokat_maly[1][0];
		cout << "y2:"; cin >> prostokat_maly[1][1];
		cout << "podaj dokladnosc obliczenia "; cin >> ilosc_prob;
		
		prostokat_duzy[0][0] = min(sx - promien,prostokat_maly[0][0]);
		prostokat_duzy[0][1] = min(sy - promien,prostokat_maly[0][1]);
		prostokat_duzy[1][0] = max(sx + promien, prostokat_maly[1][0]);
		prostokat_duzy[1][1] = max(sy + promien, prostokat_maly[1][1]);
		
         pole_prostokata = (prostokat_duzy[1][0] - prostokat_duzy[0][0]) * (prostokat_duzy[1][1]-prostokat_duzy[0][1]);
         srand(time(NULL));
		
		for(int i = 0; i< ilosc_prob;i++){
			double losowe_x = prostokat_duzy[0][0] + ((double)rand() / RAND_MAX) * (prostokat_duzy[1][0] - prostokat_duzy[0][0] );
			double losowe_y = prostokat_duzy[0][1] + ((double)rand() / RAND_MAX) * (prostokat_duzy[1][1] - prostokat_duzy[0][1] );
			double point[2] = {losowe_x ,losowe_y};
		    	(czy_w_czesci_wspolnej(point)) ? punkty_trafione ++ ;
				
				
			}
	cout << "Pole wynosi: " << punkty_trafione / ilosc_prob * pole_prostokata;
}

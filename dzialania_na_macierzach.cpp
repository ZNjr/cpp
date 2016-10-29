#include <iostream> 
#include <cmath>
 
 using namespace std;
 
 class Matrix{
  private :
 	
  void wpisz_do_tablicy(){
	 	for(int i=0;i<wiersze;i++){
 		wartosci[i] = new int[kolumny];
	 	for(int j=0;j<kolumny;j++){
 			wartosci[i][j] = i;
		 }
	 }
}
       
 	public :
	  int kolumny;
	  int wiersze;
	  int** wartosci;
   
  	void wypisz(){
  		for(int i=0;i<wiersze;i++){
 		    for(int j=0;j<kolumny;j++){
				cout.width(5);
				cout << wartosci[i][j];
	 }
 	cout << endl;
   }
}
   	void dodawanie(Matrix matrix){
		  for(int i=0;i<wiersze;i++){
	    	for(int j=0;j<kolumny;j++){
 	   			wartosci[i][j] = wartosci[i][j] + matrix.wartosci[i][j];
			}
		}
	}
  
  Matrix mnozenie(Matrix matrix){
  	Matrix macierz = Matrix(matrix.kolumny,wiersze);
	  for(int i=0;i<wiersze;i++){
  		for(int j=0;j<matrix.kolumny;j++){
  			macierz.wartosci[i][j] = 0;
			  for(int k=0;k<matrix.wiersze;k++){
  			    macierz.wartosci[i][j] += wartosci[i][k] * matrix.wartosci[k][j];
			  }	
		  }
	  }
  	return macierz;
  }
 	
	 Matrix(int ilosc_kolumn, int ilosc_wierszy):
		kolumny(ilosc_kolumn),
 		wiersze(ilosc_wierszy){
 			kolumny = ilosc_kolumn;
 			wiersze = ilosc_wierszy;
 			wartosci = new int*[kolumny];
		    wpisz_do_tablicy();
	}
 };
 
int main(){
 	
Matrix macierz = Matrix(8,8);
macierz.wypisz();
Matrix macierz_2 = Matrix(3,3);
Matrix po_mnozeniu = macierz.mnozenie(macierz_2);
po_mnozeniu.wypisz();

 }

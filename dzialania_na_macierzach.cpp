#include <iostream> 
#include <cmath>
 
 using namespace std;
 
 class Matrix{
  private :
 	
  void wpisz_do_tablicy(){
	 	for(int i=0;i<wiersze;i++){
 		wartosci[i] = new int[kolumny];
	 	for(int j=0;j<kolumny;j++){
 			wartosci[i][j] = pow(j+1,i);
		    
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
     Matrix(int ilosc_kolumn, int ilosc_wierszy):
		kolumny(ilosc_kolumn),
 		wiersze(ilosc_wierszy){
 			kolumny = ilosc_kolumn;
 			wiersze = ilosc_wierszy;
 			wartosci = new int*[wiersze];
		    wpisz_do_tablicy();
	}
 };
 
   Matrix mnozenie(Matrix matrix_1,Matrix matrix_2){
  	Matrix macierz = Matrix(matrix_2.kolumny,matrix_1.wiersze);
	  for(int i=0;i<matrix_1.wiersze;i++){
  		for(int j=0;j<matrix_2.kolumny;j++){
  			macierz.wartosci[i][j] = 0;
			  for(int k=0;k<matrix_2.wiersze;k++){
  			    macierz.wartosci[i][j] += matrix_1.wartosci[i][k] * matrix_2.wartosci[k][j];
			  }	
		  }
	  }
  	return macierz;
  }
  
  Matrix dodawanie(Matrix matrix_1,Matrix matrix_2){
		Matrix macierz = Matrix(matrix_2.kolumny,matrix_1.wiersze);
		  for(int i=0;i<matrix_1.wiersze;i++){
	    	for(int j=0;j<matrix_1.kolumny;j++){
 	   			macierz.wartosci[i][j] = matrix_1.wartosci[i][j] + matrix_2.wartosci[i][j];
			}
		}
		return macierz;
	}
  	
int main(){
Matrix macierz = Matrix(3,5);
Matrix macierz_2 = Matrix(3,3);
Matrix po_mnozeniu = mnozenie(macierz,macierz_2);
po_mnozeniu.wypisz();
}

#include <iostream> 
#include <cmath>
 
 using namespace std;

 int** dodawanie(int **matrix_1 ,int **matrix_2){
	 int** wartosci_po_dodawaniu = new int * [sizeof(matrix_1)];
 	  
	    for(int i=0;i<sizeof(matrix_1);i++){
 	   		wartosci_po_dodawaniu[i] = new int[sizeof(matrix_1)];
 	   
		for(int j=0;j<sizeof(matrix_1);j++){
 	   			wartosci_po_dodawaniu[i][j] = matrix_1[i][j] + matrix_2[i][j];
			}
		}
 	return wartosci_po_dodawaniu;
 }  
 void wypisz(int** matrix){
 	for(int i=0;i<sizeof(matrix);i++){
 	    for(int j=0;j<sizeof(matrix);j++){
		   cout.width(8);
		   cout << matrix[i][j];
	      }
 	cout << endl;
   }
}

//int** mnozenie(){	
//}
 int main(){
 	int** matrix = new int*[8];
 	    for(int i=0;i<sizeof(matrix);i++){
 		matrix[i] = new int[sizeof(matrix)];
	 	    for(int j=0;j<sizeof(matrix);j++){
 			matrix[i][j] = pow(j+1,i);
		      }
	 	}
	
 int** matrix_po_dodawaniu = dodawanie(matrix,matrix);
 wypisz(matrix);
 wypisz(matrix_po_dodawaniu);	 	
 }

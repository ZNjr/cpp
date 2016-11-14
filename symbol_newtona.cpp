#include <iostream>

using namespace std;

int main(){
	int ilosc_elementow;

	cin >> ilosc_elementow;

	int** trojkat_pascala = new int*[ilosc_elementow+1];
	
	for(int i=0;i<=ilosc_elementow;i++){
		
		trojkat_pascala[i] = new int[i+1];		
		trojkat_pascala[i][0] = 1;
	    
		if(i>0) trojkat_pascala[i][i] = 1;
		
		for(int j=1;j<i;j++)
		{
		   trojkat_pascala[i][j] = trojkat_pascala[i-1][j-1] + trojkat_pascala[i-1][j];
		}
	}
	
	  for(int i=0;i<=ilosc_elementow;i++){
		cout << trojkat_pascala[ilosc_elementow][i] << " ";
	
	}
	
	for(int i=0;i<=ilosc_elementow;i++) delete [] trojkat_pascala[i];
	delete [] trojkat_pascala;
}
	

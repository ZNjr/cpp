#include <iostream>

using namespace std;

bool filtr(int i){
	return (i%3==0) ? true: false;	
	}

void f(int t[],int d, bool (*f)(int)){
	for(int i=0;i<d;i++){
		if(f(t[i])){
			cout<<t[i]<<endl;
			}
		
		
		}	
	}

int main(){
	int t[] = {1,3,5,6,7,8,9,0,650,18,33,21,22,25,62,3,4,52,35,23,5,23,4,2,35,2,3,3,5,87,5,675,4,999};
	f(t,35,filtr);
	
	}

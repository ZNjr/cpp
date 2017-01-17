#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

class Zbior{
   public:
   	int* zbior;
	int ilosc_elementow;
   
   Zbior(int ilosc_elementow,int *elementy){
	   this->ilosc_elementow = ilosc_elementow;
	   zbior = new int[ilosc_elementow];
	   for(int i=0;i<ilosc_elementow;i++){
			zbior[i]=elementy[i];
	    }
	}
	~Zbior(){
		if(ilosc_elementow!=0) free(zbior);
		}
	Zbior(const Zbior & nzbior){
		memcpy(zbior,nzbior.zbior,ilosc_elementow*sizeof(int));
		}
	
	bool dodaj_element(int x){
		if(!find(x)){
			ilosc_elementow++;
			zbior = (int*)realloc(zbior,ilosc_elementow*sizeof(int));
			zbior[ilosc_elementow-1] = x;
			return true;
		}
		return false;
	 }
	
	bool find(int x) const{
		for(int i=0;i<ilosc_elementow;i++){
			if(zbior[i]==x) return true;			
			}
		return false;
		}
	friend ostream& operator<<(ostream& out, Zbior& set);
	
	Zbior operator*(Zbior const& set)
		{    
		   Zbior tmp = Zbior(0,0);				
			for(int i=0;i<this->ilosc_elementow;i++){
					if(set.find(this->zbior[i])) tmp.dodaj_element(this->zbior[i]);
					}	
			
			return tmp;  
	    }
	   Zbior operator-(Zbior const& set){
		  Zbior tmp = Zbior(0,0);				
			for(int i=0;i<this->ilosc_elementow;i++){
				if(!set.find(this->zbior[i])) tmp.dodaj_element(this->zbior[i]);
				}	
			return tmp;  
		   }
      };
   
   ostream& operator<<(ostream& out, Zbior& set){
	     out<<"(";
	   for(int i = 0;i<set.ilosc_elementow-1;i++){
		   out<<set.zbior[i]<<",";
		   }
		if(set.ilosc_elementow!=0)
			out<<set.zbior[set.ilosc_elementow-1]<<")";
		return out;
	   }
	    
int main(){
	int t[5] = {1,5,7,4,3};
	int s[2] = {5,4};
	Zbior set(5,t);
	Zbior z(2,s);
	Zbior l = set-z;
	//cout<<l;
	cout<<l;
	}   


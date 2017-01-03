#include <iostream>
#include <string>
using namespace std;

class Data{
	protected:
	int dzien;
	int miesiac;
	int rok;
	
	public:
		Data(int dzien,int miesiac,int rok){
				this->miesiac = (poprawny_miesiac(miesiac))? miesiac:1;
				this->dzien = (poprawny_dzien(dzien))? dzien:1; 
				this->rok = (poprawny_rok(rok))? rok:2000;  
			}
		 
		 bool s_dzien(int dzien){
			 if(poprawny_dzien(dzien)){
				 this->dzien=dzien;
				 return true;
				 }else return false; 
			 }
		 bool s_miesiac(int miesiac){
			 if(poprawny_miesiac(miesiac)){
				 this->miesiac=miesiac;
				 return true;
				 }else return false; 
			}
		 bool s_rok(int rok){
				if(poprawny_rok(rok)){
					 this->rok=rok;
					 return true;
				 }else return false; 
			 }
	     int g_dzien(){	return dzien;}	
		 int g_miesiac(){ return miesiac;}
		 int g_rok(){ return rok;}
		
		//string to_String(){
				//tu
			//}
	private:
		bool poprawny_dzien(int dzien){
			switch(miesiac){
				case 1:case 3:case 5:case 7:case 8:case 10:case 12: 
					return (dzien<=31)? true:false; 
					break;
				case 4: case 6: case 9: case 11:
					return (dzien<=30)? true:false;
					break;
				case 2:
					return (dzien<=28)? true:false;
					break;	
				}	
			return false;
		  }
	  bool poprawny_miesiac(int miesiac) { return (miesiac<=12)? true:false;}
	  bool poprawny_rok(int rok) {return (rok>=0)? true:false;}
		  		  
	};
	
int main(){
	Data d(10,10,2016);
	cout<<d.g_dzien();
	
	}


#include <iostream>
#include "Uczestnik.h"

class Node{
	public:
	Uczestnik* uczestnik;
	Node* lewy;
	Node* prawy;
	int id;
	bool ma_chusteczke = false;
	Node(Uczestnik* uczestnik, Node* lewy,Node* prawy, int id): 
		uczestnik(uczestnik),
		lewy(lewy),
		prawy(prawy),
		id(id){}
	Node(Node* lewy,Node* prawy, int id):
		lewy(lewy),
		prawy(prawy),
		id(id){}
};

class Wodzirej:public Node{
    public:
	bool zabawa_rozpoczeta;
	int nastepne_id = 0;
	Wodzirej():
		Node(0,0,0)
		{
			zabawa_rozpoczeta = false;		
			ma_chusteczke = true;
			uczestnik = new Uczestnik(Uczestnik::W); 
		}

	unsigned int dolacz(Uczestnik* osoba){
		if(kolko_puste()){
			 nastepne_id++;
			 Node* node = new Node(osoba,this,this,nastepne_id);
			 lewy = node;
			 prawy = node;
			 return nastepne_id; 
			 }
		if(jest_w_kolku(osoba) or osoba == 0 or (osoba->plec != Uczestnik::K and osoba->plec != Uczestnik::M)) return 0;
		else{
		 	
				
		}
	}
	private:
		bool jest_w_kolku(Uczestnik* osoba){
		   Node* nastepny = this->prawy;
		   while(nastepny->id!=0||nastepny!=0){
		   		if(nastepny->uczestnik==uczestnik) return true;
		   }
			return false;
		}
	inline bool kolko_puste(){
			return (prawy == 0 && lewy == 0)? true:false;
		}
};



int main(){
Wodzirej w;

Uczestnik* u = new Uczestnik(Uczestnik::K);
int wee=w.dolacz(u);
return 0;	

}

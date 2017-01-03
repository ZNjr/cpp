#include <iostream>
#include "Uczestnik.h"

class Node{
	public:
	Uczestnik* uczestnik;
	Node* next;
	Node* previous;
	int id;
	bool ma_chusteczke = false;
	Node(Uczestnik* uczestnik, Node* next,Node* previous, int id): 
		uczestnik(uczestnik),
		next(next),
		previous(previous),
		id(id){}
	Node(Node* next,Node* previous, int id):next(next),
		previous(previous),
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
			 next = node;
			 previous = node;
			 return nastepne_id; 
			 }
		if(jest_w_kolku(osoba) or osoba == 0 or (osoba->plec != Uczestnik::K and osoba->plec != Uczestnik::M)) return 0;
		else{
		 	
				
		}
	}
	private:
		bool jest_w_kolku(Uczestnik* osoba){
		   Node* nastepny = this->next;
		   while(nastepny->id!=0||nastepny!=0){
		   		if(nastepny->uczestnik==uczestnik) return true;
		   }
			return false;
		}
	inline bool kolko_puste(){
			return (next==0 && previous == 0)? true:false;
		}
};



int main(){
Wodzirej w;

Uczestnik* u = new Uczestnik(Uczestnik::K);
int wee=w.dolacz(u);
return 0;	

}

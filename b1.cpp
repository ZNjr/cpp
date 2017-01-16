
#include <iostream>
#include <cstdlib>
#include "Uczestnik.h"

using namespace std;

class Wodzirej{
    
	public:
		
	Wodzirej()
		{	
			node = new Node(new Uczestnik(Uczestnik::W),0,0,0);
			node->previous = node;
			node->next = node;
			nastepne_id = 0;
			ilosc_uczestnikow = 1;
			ilosc_kobiet = 0;
			ilosc_menzczyzn = 0;
			zabawa_rozpoczeta = false; 
			posiadacz_chusteczki = node;
		
		}
										
	unsigned int dolacz(Uczestnik* osoba);
	unsigned int dolacz(Uczestnik* osoba, unsigned int pozycja);
	bool rozpocznij();
	bool zakoncz();
	bool zrezygnuj(Uczestnik* osoba);
	bool zrezygnuj(unsigned int id);
	bool przekaz(Uczestnik* osoba);
	bool przekaz(unsigned int pozycja);
	void uczestnicy() const;
	void uczestnicy(Uczestnik::Plec p) const;
	
	unsigned int liczba() const {return ilosc_uczestnikow;}
	Uczestnik * wodzirej() const {return node->uczestnik;}
	
	private:
	
		class Node{
			public:
			Uczestnik* uczestnik;
			Node* next;
			Node* previous;
			unsigned int id;
	
		Node(Uczestnik* uczestnik, Node* next,Node* previous, int id): 
		uczestnik(uczestnik),
		next(next),
		previous(previous),
		id(id){}
	};
	
	Node* node;
	unsigned int nastepne_id;
	int ilosc_uczestnikow;
	int ilosc_kobiet;
	int ilosc_menzczyzn;
	bool zabawa_rozpoczeta;
	Node* posiadacz_chusteczki;
	
	inline bool kolko_puste(){
			return (node->next==0 and node->previous == 0)? true:false;
		}
			
	void inkrementuj(Uczestnik* osoba){
		nastepne_id++;
	    ilosc_uczestnikow++;
		if(osoba->plec == Uczestnik::K) ilosc_kobiet++;
		if(osoba->plec == Uczestnik::M) ilosc_menzczyzn++;
	}
	
	Node* osoba_na_pozycji(int pozycja){
		Node* tmp = node;
		for(int i=0;i<pozycja;i++) tmp = tmp->previous;
		return tmp;
	}
	
	Node* uczestnik_to_node(Uczestnik* osoba){
		if(kolko_puste()) return 0;
		Node* tmp = node->next;
		while(tmp->id!=0){
			if(tmp->uczestnik == osoba) return tmp;
			tmp = tmp->next;
		}
		return 0;
	}
	Node* node_with_id(unsigned int id){
		if(kolko_puste()) return 0;
		Node* tmp = node->next;
		while(tmp->id!=0){
			if(tmp->id == id) return tmp;
			tmp=tmp->next;
		}
		return 0;
	}
	void rezygnacja(Node* osoba){
		osoba->previous->next=osoba->next;
		osoba->next->previous=osoba->previous;
	}
	bool moze_przekazac(Node* osoba){
		return (osoba->uczestnik->plec != Uczestnik::W and osoba->uczestnik->plec != posiadacz_chusteczki->uczestnik->plec)? true:false;
	}
};

unsigned int Wodzirej::dolacz(Uczestnik* osoba){
		if(uczestnik_to_node(osoba) != 0 or osoba == 0 or (osoba->plec != Uczestnik::K and osoba->plec != Uczestnik::M)) return 0;
		
		inkrementuj(osoba);	
		
		if(kolko_puste()){
			 	node->next = new Node(osoba,node,node,nastepne_id);
				node->previous = node->next;
			}
			else{
			 	Node* tmp = node->next;
				node->next = new Node(osoba,tmp,node,nastepne_id);	 	   
				tmp->previous = node->next;
			}
		return nastepne_id;	
	}

unsigned int Wodzirej::dolacz(Uczestnik* osoba, unsigned int pozycja){
		if(uczestnik_to_node(osoba)!=0 or osoba == 0 or (osoba->plec != Uczestnik::K and osoba->plec != Uczestnik::M) or pozycja>=ilosc_uczestnikow) return 0;
		inkrementuj(osoba);
		if(kolko_puste()){
				node->previous = new Node(osoba,node,node,nastepne_id);
				node->next = node->previous;
			}else{
				Node* tmp = osoba_na_pozycji(pozycja);
				Node* tmp_pre = tmp->previous; 	
				Node* n_node = new Node(osoba,tmp,tmp_pre,nastepne_id);
				tmp->previous = n_node;
				tmp_pre->next = n_node; 
			}
		return nastepne_id;	
	}

bool Wodzirej::rozpocznij(){
	   if(!zabawa_rozpoczeta and ilosc_uczestnikow!=0 and ilosc_kobiet !=0 and ilosc_menzczyzn !=0){
	   		posiadacz_chusteczki = node->next;
	 		zabawa_rozpoczeta = true;	
	   	return true;
	   } 
	   	return false; 
	}

bool Wodzirej::zakoncz(){
	if(zabawa_rozpoczeta){
		posiadacz_chusteczki = node;
	 	zabawa_rozpoczeta = false;
	return true;
	}
	return false;
}

bool Wodzirej::zrezygnuj(Uczestnik* osoba){
	Node* tmp = uczestnik_to_node(osoba);
		if(tmp!=0 and osoba->plec != Uczestnik::W and osoba!=0 and tmp!=posiadacz_chusteczki){		
			rezygnacja(tmp);
			return true;
		}
	return false;
}

bool Wodzirej::zrezygnuj(unsigned int id){
	Node* tmp = node_with_id(id);
		if(tmp!=0 and posiadacz_chusteczki!=tmp and tmp->uczestnik->plec != Uczestnik::W){
			rezygnacja(tmp);
			return true;
		}
	return false;
}

bool Wodzirej::przekaz(Uczestnik* osoba){
		if(zabawa_rozpoczeta and uczestnik_to_node(osoba)!=0){
			Node* tmp = uczestnik_to_node(osoba);
			if(moze_przekazac(tmp)){
				posiadacz_chusteczki = tmp;
				return true;
			}
		}	
	return false;
}

bool Wodzirej::przekaz(unsigned int pozycja){
	if(zabawa_rozpoczeta and node_with_id(pozycja)!=0){
			Node* tmp = node_with_id(pozycja);
			if(moze_przekazac(tmp)){
				posiadacz_chusteczki = tmp;
				return true;
			}
		}	
	return false;
}

 void Wodzirej::uczestnicy() const{
	Node* tmp = node;
	do{
		cout<<"plec: "<<tmp->uczestnik->plec<<", nr: "<<tmp->id<<endl;
		tmp=tmp->previous;
	}while(tmp != node);
}

 void Wodzirej::uczestnicy(Uczestnik::Plec p) const{
		Node* tmp = node;
	do{
		if(tmp->uczestnik->plec == p){
			cout<<"nr: "<<tmp->id<<endl;
		}
		tmp=tmp->next;		
	}while(tmp->id!=0);	
}

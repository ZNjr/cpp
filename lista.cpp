#include <iostream>
using namespace std;

struct Node{
	Node* n;
	Node* p;
	int dane;
	};

struct List{
	Node * pierwszy;
	Node * ostatni;
	};
	
void init(List *l){
	l->pierwszy=0;
	l->ostatni=0;
	}	

Node* initNode(int nowe_dane, Node* poprzedni, Node* nastepny){
	Node * nowy = new Node;
	nowy->dane = nowe_dane;
	nowy->n=nastepny;
	nowy->p=poprzedni;
	return nowy;
	}
	
inline bool pusta(List* l){
return (l->ostatni!=0 && l->pierwszy!=0)? true:false;
}	

void dodajPierwszy(int dane,List* lista){
	list->pierwszy = initNode(dane,0,0);  
	list->ostatni = list->pierwszy;	
}	

void dodajNaPoczatek(int dane,List* lista){
	if(pusta(lista)) dodajPierwszy(dane,lista);
		else{
		list->pierwszy->p = initNode(dane,0,list->pierwszy);
		list->pierwszy = list->pierwszy->p;
		}
	}
	
void dodajNaKoniec(int dane,List* lista){
	if(pusta(lista)) dodajPierwszy(dane,lista);
	else{
		list->ostatni->n=initNode(dane,list->ostatni,0);
		list->ostatni=list->ostatni->n;
	}
}	

void dodajNaPozycji(int index,int dane,List* lista){
	if(index==0) dodajPierwszy(dane,lista);
	int i=0;
	while(i<index){
	
	i++;
	}
}	
	
void zwolnij(Node* w){
	delete w;
}
   void zwolnij(List* list){
		Node* kolejny = list->pierwszy;
		while(kolejny){
			Node* tmp = kolejny->n;
			zwolnij(kolejny);
			kolejny=tmp;
			}
		}



void wypisz(Node *w){
	cout<<w->dane<<" ";
	}	
	
void wypisz(const List* list){
	Node * kolejny = list->pierwszy;
	while(kolejny){
		wypisz(kolejny);
		kolejny=kolejny->n;
		}
	}	
int main(){
	List* list = new List;
	init(list);
	wypisz(list);
}

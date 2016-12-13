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
return (l->ostatni==0 && l->pierwszy==0) ? true:false;
}	

void dodajPierwszy(int dane,List* lista){
	lista->pierwszy = initNode(dane,0,0);  
	lista->ostatni = lista->pierwszy;	
}	

void dodajNaPoczatek(List* lista, int dane){
	if(pusta(lista)) dodajPierwszy(dane,lista);
		else{
		lista->pierwszy->p = initNode(dane,0,lista->pierwszy);
		lista->pierwszy = lista->pierwszy->p;
		}
	}
	
void dodajNaKoniec(int dane,List* lista){
	if(pusta(lista)) dodajPierwszy(dane,lista);
	else{
		lista->ostatni->n=initNode(dane,lista->ostatni,0);
		lista->ostatni=lista->ostatni->n;
	}
}	
Node* adresElementu(List* lista,int x){
	Node* element = lista->pierwszy;
		int i=0;
		while(i<x-1){
			element = element->n; 
			i++;
		}
		return element;
	}
void dodajNaPozycji(int index,int dane,List* lista){
	if(index==0) dodajPierwszy(dane,lista);
	Node * el = adresElementu(lista,index);
	Node * tmp = el->n;
	el->n = initNode(dane,el,tmp);
	tmp->p = el;
}	
void zwolnij(Node* w){
	delete w;
}

void usun(int index,List* lista){
	Node* el = adresElementu(lista,index)->n;
	Node* nastepny = el->n;
	Node* poprzedni = el->p;
	poprzedni->n = nastepny;
	nastepny->p = poprzedni;
	zwolnij(el);
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
		cout<<endl;
	}	
void wypiszOd(int x,List* list){
	Node * kolejny = adresElementu(list,x);
	while(kolejny){
		wypisz(kolejny);
		kolejny=kolejny->n;
		}
		cout<<endl;
	
	}
void wypiszDo(int x,List* list){
	Node* element = list->pierwszy;
		int i=0;
		while(i<x){
			wypisz(element);
			element = element->n; 
			i++;
		}
	cout<<endl;
	}
		
int main(){
	List* list = new List;
	init(list);
	dodajNaPoczatek(list,10);
	dodajNaPoczatek(list,20);
	dodajNaPoczatek(list,30);
	dodajNaPoczatek(list,40);
	dodajNaPoczatek(list,50);
	dodajNaPoczatek(list,60);
	dodajNaPoczatek(list,70);
	dodajNaPozycji(2,99,list);
	wypisz(list);
	usun(2,list);
	wypisz(list);
	wypiszDo(4,list);
	wypiszOd(4,list);
}

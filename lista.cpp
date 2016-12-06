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

Node* createNode(int nowe_dane, Node* poprzedni, Node* nastepny){
	Node * nowy = new Node;
	nowy->dane = nowe_dane;
	nowy->n=nastepny;
	nowy->p=poprzedni;
	return nowy;
	}
	
void addNode(int dane,List* list){
	if(!list->pierwszy){
		list->pierwszy = createNode(dane,0,0);  
		list->ostatni = list->pierwszy;
		}else{
	//	Node* tmp = createNode(dane,0,list->pierwszy);
		list->pierwszy->p = createNode(dane,0,list->pierwszy);
		list->pierwszy = list->pierwszy->p;
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
	addNode(5,list);
	addNode(6,list);
	addNode(7,list);
	addNode(8,list);
	addNode(9,list);
	addNode(10,list);
 
	wypisz(list);
 }

#ifndef ONP_H
#define ONP_H
	
	#include "operators.cpp"
	#include <iostream>
	#include <string>
	#include <stack>
	#include <vector>
	#include <cmath>

using namespace std;

class Op{
	public:

		enum ilosc_argumentow {liczba,jeden,wiele};
		ilosc_argumentow ilosc_arg;
		string s;
		int waga;	
		double(* dzialanie)(vector <double> tablica);
		double(* stala)();
	
		Op(string s,int waga, double(* dzialanie)(vector <double> tablica),ilosc_argumentow ilosc_arg):s(s),waga(waga),dzialanie(dzialanie),ilosc_arg(ilosc_arg){}
		Op(string s,int waga, double(* stala)(),ilosc_argumentow ilosc_arg):s(s),waga(waga),stala(stala),ilosc_arg(ilosc_arg){}
		Op(string s,int waga):s(s),waga(waga){}
		Op(){}
	};
	
class Onp{
	public:
		
		Onp(){}
		Onp(string wyraz){
		   this->hierarchia = {Op("-U",0),Op(",",3),Op("*",2,multiplicate,Op::wiele),Op("/",2,division,Op::wiele),Op("-",3,substract,Op::wiele),Op("+",3,add,Op::wiele),Op("(",4),Op(")",4)};
		   this->ilosc_el = this->hierarchia.size();
		   this->wyraz = wyraz; 
		}
	
	string to_string();
	bool add_function(string nazwa,double (* dzialanie)(vector <double> tablica),Op::ilosc_argumentow arg);
	bool add_constans(string nazna,double (*constans)()); 
	void to_onp();
	double policz();
	void zmien_wyrazenie(string nowe);
	
	private:
	string wyraz;
	int ilosc_el;
	vector <Op> hierarchia;
	vector <string> tablica;
	
	int miejsce_w_hierarchi(string s){ 
			for(int i=0;i<ilosc_el;i++){
				if(hierarchia[i].s==s) return hierarchia[i].waga;	
				}
			return -1;
		}
    bool cyfra(char s){
			int tmp = (int)s;
			return (tmp >= (int)'0'  && tmp <= (int)'9' || tmp == (int)'.');
		}

	string liczba(int od){
		int i=od;
		string tmp="";
		while(cyfra(wyraz[i]) && i<wyraz.size()){
				tmp+=wyraz[i];
				i++;
			}
			return tmp;
		}

	string parse_string(int od){
			string tmp="";
			string to_return = "";
			bool trwa_sprawdzanie = false;
			for(int i=0;i<ilosc_el;i++){
					tmp="";
					if(hierarchia[i].s[0]==wyraz[od]){
					 		int j=0;
							trwa_sprawdzanie = true;
					while(trwa_sprawdzanie && hierarchia[i].s[j]!=0){
						if(wyraz[od+j] == hierarchia[i].s[j]) 
						{
							tmp+=wyraz[od+j];
							j++;
						}else{
							tmp="";
							trwa_sprawdzanie=false;
							}								
							if(tmp.size()>to_return.size()) to_return = tmp;
						} 	
					}
				}
			 return (to_return.size()>tmp.size())?to_return:tmp;
			}
	
	Op* string_to_op(string s){
		for(int i=0;i<ilosc_el;i++){
			if(hierarchia[i].s==s) return &hierarchia[i];	
		}
	return 0;
	}
};	

string Onp::to_string(){
		string tmp = "";
			for(int i=0;i<tablica.size();i++){
				tmp+=tablica[i];
			}
		return tmp;
	}
void Onp::to_onp(){
		stack <string> stos;
		int i=0;
		while(wyraz[i]!=0 && i<wyraz.size())
			{
				if(cyfra(wyraz[i])){
					string p = liczba(i);
					tablica.push_back(p);
					i+=p.size();
				}else{
					string p = parse_string(i);
							if(stos.empty() || p=="(" || p=="-U") stos.push(p);
							else if(miejsce_w_hierarchi(p)==-2) tablica.push_back(p);
							else if(miejsce_w_hierarchi(stos.top())<=miejsce_w_hierarchi(p) && p!=")"){
								while(!stos.empty() && miejsce_w_hierarchi(stos.top())<=miejsce_w_hierarchi(p)){
									tablica.push_back(stos.top());
									stos.pop();
									}
								stos.push(p);
							}else if(p==")"){
									while(stos.top()!="("){
										tablica.push_back(stos.top());	
										stos.pop();
									}
								stos.pop();
							}
							else stos.push(p);
					i+=p.size();
				}
			}
				while(!stos.empty()){
					tablica.push_back(stos.top());
					stos.pop();
				  }
		}

bool Onp::add_function(string nazwa,double (* dzialanie)(vector <double> tablica),Op::ilosc_argumentow arg){
		int priorytet_funkcji = 1;
		if(miejsce_w_hierarchi(nazwa) !=-1) return false;
			Op nw_operator = Op(nazwa,priorytet_funkcji,dzialanie,arg);
			hierarchia.push_back(nw_operator);
			ilosc_el++;
	    return true;
	}	

bool Onp::add_constans(string nazwa,double(*stala)()){
	int priorytet_funkcji = -2;
	if(miejsce_w_hierarchi(nazwa) !=-1) return false;
			Op nw_operator = Op(nazwa,priorytet_funkcji,stala,Op::liczba);
			hierarchia.push_back(nw_operator);
			ilosc_el++;
		return true;
	}

double Onp::policz(){
	stack <double> stos;
	vector <double> tmp_table;
		bool byl_przecinek = false;
		for(int i=0;i<tablica.size();i++){
		
	      	if(cyfra(tablica[i][0])) stos.push(stod(tablica[i]));
			else if(tablica[i]=="-U"){
	      		stos.top() = 0-stos.top();      	
		  	}else if(tablica[i]==","){
		 		if(byl_przecinek){
		 			tmp_table.push_back(stos.top());
		 			stos.pop();
				 }else{
				 	for(int i=0;i<2;i++){
				 		tmp_table.push_back(stos.top());
						stos.pop(); 
						}
					byl_przecinek = true;
					}
			}else{
				Op* current_op = string_to_op(tablica[i]);
				if(tmp_table.empty() && current_op->ilosc_arg == Op::wiele){
						for(int i=0;i<2;i++){
				 		tmp_table.push_back(stos.top());
						stos.pop(); 
					}
				}else if(tmp_table.empty() && current_op->ilosc_arg == Op::jeden){
					tmp_table.push_back(stos.top());
		 			stos.pop();
				}
			 	 	if(current_op->ilosc_arg != Op::liczba){
					 	byl_przecinek=false;	
			 			stos.push(current_op->dzialanie(tmp_table));
			 			tmp_table.clear();
					  }else stos.push(current_op->stala());
				}
			}
	return stos.top();
}
void Onp::zmien_wyrazenie(string nowe){
	wyraz=nowe;
	tablica.clear();
	to_onp();
}
#endif

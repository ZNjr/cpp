#include "onp.h"
#include "functions.cpp"
using namespace std;

int main(){
 	string wyrazenie;
	cin>>wyrazenie;
	Onp onp = Onp(wyrazenie);
	
	///domyslne funkcje w pliku operators.cpp
	
	onp.add_function("max",maximum,Op::wiele);
	onp.add_function("pow",power,Op::wiele);
	onp.add_function("abs",absolute,Op::jeden);
	onp.add_function("!",factorial,Op::jeden);
	onp.add_constans("pi",num_pi);
	onp.add_constans("e",euler);
	onp.add_function("sin",sinus,Op::jeden);
	onp.add_function("cos",cosinus,Op::jeden);
	onp.add_function("newton",newton,Op::wiele);
	
	////po dodaniu funckij wywolac to_onp////
	onp.to_onp();
	//////
	//cout<<onp.to_string();
	
	cout<<onp.policz()<<endl;
	
	while(1){
		cin>>wyrazenie;
		if(wyrazenie=="END") break;
		onp.zmien_wyrazenie(wyrazenie);
		cout<<onp.policz()<<endl;
	}
	return 0;
}

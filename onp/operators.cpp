	#ifndef OPERATORS_CPP
	#define OPERATORS_CPP
	#include <vector>
	#include <cmath>	
	 
	 using namespace std; 
	
	double multiplicate(vector <double> table){
		return table[1]*table[0];
	}	
	
	double division(vector <double> table){
		return table[1]/table[0];	
	}
	
	double substract(vector <double> table){
		return table[1]-table[0];
	}
	
	double add(vector <double> table){
		return table[1]+table[0];
	}
	
#endif

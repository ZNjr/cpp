	#include <vector>
	#include <cmath>
	
	double maximum(vector <double> table){
		double maximum = table[0];
		for(int i=1;i<table.size();i++)
			if(table[i]>maximum) maximum = table[i];
		return maximum;
	}
		double power(vector <double> table){
		return pow(table[1],table[0]);
	}
	
	double absolute(vector <double> table){
		return abs(table[0]);
	}
	double factorial(vector <double> table){
		double silnia = 1;
		if(table[0] == 0);
		else{
			for(int i=1;i<=table[0];i++){
				silnia*=i;
				}
			
		}
	 return silnia;
	}
	
	double num_pi(){
		return 3.14159265358979323846;
	}
	double euler(){
		return 2.7182818284590452;
	}
	
	double newton(vector <double> table){
		double newton = 1;      
		for( unsigned int i = 1; i <= table[0]; i++)   
			{
			newton = newton * ( table[1] - i + 1 ) / i;   
			}
		return newton;
	}
 	
	double sinus(vector <double> table){
		return sin(table[0]);
	}
	double cosinus(vector <double> table){
		return cos(table[0]);
	}

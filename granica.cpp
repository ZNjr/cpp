#include <iostream>
#include <cmath>

using namespace std;

void granica(double(*f)(double),double(*g)(double)){
	for(int i=1;i<20;i++){
		cout<<f(g(i))<<endl;
		
		}
	}

double f(double x){
	return sin(x)/x;
	}
double ciog(double n)
{
	return 1/pow(n,2);
	}
int main()
{
	granica(f,ciog);
}

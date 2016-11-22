#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <limits>
using namespace std;
 
int liczbaLosowa (int a, int b){
        return rand()%(b-1-a)+a;
}
 
double liczbaLosowa(double a,double b){
        return (double)rand()/RAND_MAX*(b-numeric_limits<double>::min()-a)+a;
}
int main(){
        cout << setprecision(18);
        srand(time(0));
        cout << liczbaLosowa(5,10) << endl;
        cout << liczbaLosowa(5.5,10.5) << endl;
        cout << numeric_limits<double>::min();
}
 

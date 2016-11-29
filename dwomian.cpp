#include <iostream>
using namespace std;

unsigned int npok( unsigned int n, unsigned int k )
{
    if( k == 0 || k == n ) return 1;
   
    if( n > 0 && k > 0 && n > k ) return npok( n - 1, k ) + npok( n - 1, k - 1 );
   
}

int main()
{
    int n, k;
    << "Podaj n: ";
    cin >> n;
    cout << "Podaj k: ";
    cin >> k;
    cout << "Wynik: " << npok( n, k );
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;
class Przestrzen:private vector<double>{
	public:
		Przestrzen() {
			push_back(1);
		}
		Przestrzen(vector<double>przestrzen){
			double suma = 0;
			for (unsigned int i = 0;i < przestrzen.size();i++)
				suma += przestrzen[i];
			if(suma <= (1+1/CHAR_MAX) && suma >= (1-1/CHAR_MAX) )
				for (int i = 0;i < przestrzen.size();i++)
					push_back(przestrzen[i]);
			}

		bool operator=(vector<double> przestrzen) {
			double suma = 0;
			for (unsigned int i = 0;i < przestrzen.size();i++)
				suma += przestrzen[i];
			if (suma <= (1 + 1 / CHAR_MAX) && suma >= (1 - 1 / CHAR_MAX)) {
				clear();
				for (int i = 0;i < przestrzen.size();i++)
					push_back(przestrzen[i]);
				return true;
			}
			else return false;
		}

	public:
		using vector<double>::at;
		using vector<double>::clear;
};

int main() {
	vector<double> ddd;
	ddd.push_back((double)1/2);
	ddd.push_back((double)1/2);
	Przestrzen przestrzen(ddd);
	cout << przestrzen.at(0);
	int i;
	cin >> i;
}

#include <iostream>
using namespace std;

int ilosc_liter(char* str){
	int i=0;
	while(str[i]!='\0' && str[i]!='\n' && str[i]!=' '){
		i++;
	};
	return i;
}

int ilosc_slow(char* str){
	int i=0;
	int slowa=1;
	while(str[i]!='\0'){
		if(str[i]==' ') slowa++;
	i++;
	}
return slowa;
}

int ktory_element(const char* klucz,char x){
	int i=0;
	while(klucz[i]!=x && (int)klucz[i]!=(int)x+32) i++;
	return i;
	
}

char* rozszyfruj(char* ch,const char* klucz){
	int i=0;
	while(ch[i]!='\0'){
			if((int)ch[i]>96 && (int)ch[i]<123){
			ch[i]=(97+ktory_element(klucz,ch[i]));
			
		}
		if((int)ch[i]>64 && (int)ch[i]<91){
			ch[i]=(65+ktory_element(klucz,ch[i]));	
			}	
	i++;	
	}
	return ch;
}
char* szyfruj(char* ch,const char* klucz){
	int i=0;
	while(ch[i]!='\0'){
		if((int)ch[i]>96 && (int)ch[i]<123){
			ch[i]=klucz[(int)ch[i]-97];
		}
		if((int)ch[i]>64 && (int)ch[i]<91){
			ch[i]=(int)klucz[(int)ch[i]-65]-32;	
		}	
	i++;	
	}
	return ch;
}


int main()
{
char napis[]="Ala ma kota";
char* z = szyfruj(napis,"zyxwvutsrqponmlkjihgfedcba");
cout<<endl<<rozszyfruj(z,"zyxwvutsrqponmlkjihgfedcba");
}

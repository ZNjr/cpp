// Zbigniew Najder
#include <cstdlib>
#include <cstdio>
#include <cstring>
class Table{
	public: 
	int ** tb;
	int ilosc_wierszy;
	
	Table(int wiersze){
		ilosc_wierszy = wiersze;
		tb = (int**)malloc(ilosc_wierszy*sizeof(int*));
		wprowadz_dane();
	}
	~Table(){
		for(int i=0;i< ilosc_wierszy;i++){
			free(*(tb+i));
		}
		free(tb);
	}
	void wypisz(){
   		for(int i=0;i<ilosc_wierszy;i++){
  			for(int j=1;j<=*(*(tb+i));j++){
  			printf("%d ",*(*(tb+i)+j));
  	 		}
		printf("%c",'\n');
  }
  printf("%c",'\n');
}	 
 void kopiowanie(){
 	
	int nr_wiersza;
 	scanf("%d",&nr_wiersza);
	ilosc_wierszy++;
    
	int ilosc_el = *(*(tb+nr_wiersza));
	tb = (int**)realloc(tb,ilosc_wierszy*sizeof(int*));
	*(tb+ilosc_wierszy-1) = (int*)malloc((ilosc_el+1)*sizeof(int));
	 
	 memcpy(*(tb+ilosc_wierszy-1),*(tb+nr_wiersza),(ilosc_el+1)*sizeof(int));
}

void usuwanie(int wiersz,int n){
	for(int i=wiersz;i<ilosc_wierszy-n;i++)
		{
		 int ilosc_elementow = *(*(tb+i+n))+1;
		*(tb+i) = (int*)realloc(*(tb+i),ilosc_elementow*sizeof(int));
		memcpy(*(tb+i),*(tb+i+n),ilosc_elementow*sizeof(int));
     }		
	for(int i=ilosc_wierszy-n;i<ilosc_wierszy;i++) free(*(tb+i));
	ilosc_wierszy-=n;
	}

void zamiana(){
    	int wiersz_1;
    	int wiersz_2;
    	scanf("%d %d",&wiersz_1,&wiersz_2);
		int ilosc_elementow_1 = *(*(tb+wiersz_1))+1;
		int ilosc_elementow_2 = *(*(tb+wiersz_2))+1;
		
		int* zp = (int*)malloc(ilosc_elementow_1*sizeof(int));
		
		memcpy(zp,*(tb+wiersz_1),ilosc_elementow_1*sizeof(int));
	   *(tb+wiersz_1) = (int*)realloc(*(tb+wiersz_1),ilosc_elementow_2*sizeof(int));
		memcpy(*(tb+wiersz_1),*(tb+wiersz_2),ilosc_elementow_2*sizeof(int));	
		*(tb+wiersz_2) = (int*)realloc(*(tb+wiersz_2),ilosc_elementow_1*sizeof(int));
		memcpy(*(tb+wiersz_2),zp,ilosc_elementow_1*sizeof(int));	
		free(zp); 	
	}
	
void podwojenie(){
	int nr_wiersza;
	scanf("%d",&nr_wiersza);
	
	*(tb+nr_wiersza) = (int*)realloc(*(tb+nr_wiersza),(*(*(tb+nr_wiersza))*2+1)*sizeof(int));
	
	int ilosc_elementow = *(*(tb+nr_wiersza));
	
	for(int i = 1;i<=ilosc_elementow;i++){
		*(*(tb+nr_wiersza)+ilosc_elementow+i)=*(*(tb+nr_wiersza)+i);
		}
		
	*(*(tb+nr_wiersza)) *= 2; 
}

void blok(){
   int kolumna,wiersz;
   scanf("%d %d",&wiersz,&kolumna);   
   kolumna++;
   int min = wiersz;
   int max = wiersz;
   
   int element = *(*(tb+wiersz)+kolumna);	
   		for(int i=wiersz+1;i<ilosc_wierszy;i++){
   				if(*(*(tb+i))<kolumna) break;
		   		if(*(*(tb+i)+kolumna)==element) max++; else break;
			}
		for(int i=wiersz-1;i>=0;i--){
			if(*(*(tb+i))<kolumna) break;
			if(*(*(tb+i)+kolumna)==element) min--; else break; 
		}
		
	int usun_od = 0;
	bool usuniete = false;
	bool trwa_usuwanie = false;
	int usun_do = 0;
	int next = min;
	for(int i=min;i<=max;i++){
		bool x = sprawdz_kolomny(next,kolumna,element);
			if(x){
				if(!trwa_usuwanie) usun_od = next;
				usun_do = next; 			
				trwa_usuwanie = true;
				if(i==max){
					usuwanie(usun_od,usun_do-usun_od+1);
				}
			}else{
				if(trwa_usuwanie){
					usuwanie(usun_od,usun_do-usun_od+1);
					usuniete = true;
					trwa_usuwanie = false;
				}
			}
			if(usuniete){
				next=next-(usun_do-usun_od);
				usuniete=false;			
			}else{
				next++;
			}
		}
	}
	
 private:  

bool sprawdz_kolomny(int wiersz,int kolumna, int element){	

	int ilosc_elementow = *(*(tb+wiersz));
	int min = kolumna;
	int max = kolumna;
    
    for(int i=kolumna-1;i>0;i--){
		if(*(*(tb+wiersz)+i)==element){
			min--;
		}else break;
	}
	for(int i=kolumna+1;i<=ilosc_elementow;i++){
		if(*(*(tb+wiersz)+i)==element){
			max++;
		}else break;
	}
	
	if(min == 1 && max == ilosc_elementow){
		return true;
	}else{
		usun_elementy(wiersz,min,max-min+1);
		return false;
	}
}

 void usun_elementy(int wiersz,int kolumna, int n){
	int ilosc_elementow = *(*(tb+wiersz));
		for(int i=kolumna;i<=ilosc_elementow-n;i++){
			*(*(tb+wiersz)+i) = *(*(tb+wiersz)+i+n);
		}
	*(tb+wiersz) = (int*)realloc(*(tb+wiersz),(ilosc_elementow-n+1)*sizeof(int));
	*(*(tb+wiersz))-=n;
}
   void wprowadz_dane(){
	 int kolumny;
	 for(int i=0;i<ilosc_wierszy;i++)
   	{
	scanf("%d",&kolumny);
	*(tb + i) = (int*)malloc((kolumny+1) *sizeof(int)); 	
	*(*(tb+i)) = kolumny;
	for(int j=1;j<=kolumny;j++)
	  {
	  	int wartosc;
   	    scanf("%d",&wartosc);			
	  *(*(tb+i)+j) = wartosc;
		  }
   		}		
	} 
};

int main(){
	int wiersze;
	scanf("%d",&wiersze);
	Table table = Table(wiersze);
	char dzialanie;
	while(dzialanie!='K'){
		scanf("%c",&dzialanie);
		switch(dzialanie){
		  case 'K': break; 
		  case 'W':
		  table.wypisz();
		  break;
		  case 'U':
		  int wiersz;
		  scanf("%d",&wiersz);
		  table.usuwanie(wiersz,1);
		  break;
		  case 'Z':
		  table.zamiana();
		  break;
		  case 'P':
		  table.podwojenie();
		  break;
		  case 'C':
		  table.kopiowanie();
		  break;	
		  case 'S':
		  table.blok();
		  break;
		}
	}
	return 0;
}

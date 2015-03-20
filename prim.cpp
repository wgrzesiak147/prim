#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <time.h>
#include <conio.h>
#include <windows.h>

using namespace std;



struct krawedzie {
	int x;
	int y;
	int waga;

};






int main() {
cout<<"liczbea wierzcholkow : ";
int liczba_wierzcholkow;
int x,y;
int stopien_wypelnienia;
float ile_krawedzi;	
cin>>liczba_wierzcholkow;
cout<<"stopien wypelnienia : ";
cin>>stopien_wypelnienia;
ile_krawedzi=(stopien_wypelnienia*0.01) * ((((liczba_wierzcholkow)*(liczba_wierzcholkow))-(liczba_wierzcholkow))/2);
int tablica[liczba_wierzcholkow][liczba_wierzcholkow];
x=ile_krawedzi;
y=liczba_wierzcholkow;
int tablica_krawedzi[x];
srand (time(NULL));

///////////////////////////////////////////////////////////////////////////////////////  warunek

	if(ile_krawedzi<(liczba_wierzcholkow-1)) // Sprawdzam poprawna ilosc krawedzi
		{
		cout<<" Za male wypelnienie!!!! "<<endl;
		system("PAUSE");
		}
		else

{

////////////////////////////////////////////////////////////////////////////////////// wypelnienie 0

for (int i=0;i<liczba_wierzcholkow;i++)
{
for (int j=0;j<liczba_wierzcholkow;j++)
{
tablica[i][j]=0;
}
}




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////Diagonala



for (int i=0;i<liczba_wierzcholkow;i++)  // w diagonali ustalam znak specjalny 
	{
	tablica[i][i]=-1;

		
	}
	
///////////////////////////////////////////////////////////////////////////////////////Tablica krawedzi



for (int i=0;i<x;i++)
{
	tablica_krawedzi[i]=i+1;
}



//////////////////////////////////////////////////////////////////////////////////////losowanie i wype³nianie



		for (int i=0;i<x;i++)
		
		{
			int e= rand() %y+0;
			int u= rand() %y+0;
			if(tablica[u][e] == 0)
			{
			tablica[u][e]=tablica_krawedzi[i];
			tablica[e][u]=tablica[u][e];
			}
			else
			{
			i--;
			}
		
		}


	
	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	COUT
 
 
 
for (int i=0;i<liczba_wierzcholkow;i++)
	{
	for (int j=0;j<liczba_wierzcholkow;j++)
      {
      	cout<<tablica[j][i]<<" ";;
      }	
	cout <<endl;
	}
	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////PRIM
cout<<endl;

/////////////////////////////////////////////////////////////////Wypelniam tablice
krawedzie mst[y-1];
int rozpatrzone[y];
int nierozpatrzone[y];
krawedzie tabkrawedzi[x];

for (int i=0;i<y;i++)
{
	nierozpatrzone[i]=1;
	rozpatrzone[i]=0;
}


///////////////////////////////////////////////////////////Algorytm

 	
int m;
int d=0;
rozpatrzone[0]=1;
nierozpatrzone[0]=1;



   
for (int f=0;f<y;f++)
{
m=0;


		for (int i=0;i<y;i++)
		{
				if(rozpatrzone[i]==1)
				{
					
						for(int p=0;p<y;p++)
						{
						cout<<" ";	
							if(nierozpatrzone[p]==1)
							{
								 if (tablica[i][p] !=0 && tablica[i][p] != -1)
									{
									
									tabkrawedzi[m].x=i;
									tabkrawedzi[m].y=p;
									tabkrawedzi[m].waga=tablica[i][p];
									m++;
								
									}
							}	
						}
				
				}
				
		}
				int min=x+1;
				int indeks;
				
				
				
				
					for(int b=0;b<m;b++)
					{
						if (tabkrawedzi[b].waga<min && tabkrawedzi[b].waga !=0) ////znajduje minimum
						{
						min=tabkrawedzi[b].waga;
						indeks=b;
						}
					}	
					
					
				
				mst[d]=tabkrawedzi[indeks];/////wpisuje do mst
				d++;
				int wartoscx=tabkrawedzi[indeks].x;
				int wartoscy=tabkrawedzi[indeks].y;
				
				rozpatrzone[wartoscy]=1;
				nierozpatrzone[wartoscy]=0;
				rozpatrzone[wartoscx]=1;
				nierozpatrzone[wartoscx]=0;
				
				
				for (int b=0;b<m;b++)
				{
					tabkrawedzi[b].x=0;
					tabkrawedzi[b].y=0;
					tabkrawedzi[b].waga=0;
				}
	
}

    
		
		
///////////////////////////////////////////////////////////////////////////////////////COUT
cout<<endl;
for (int i=0;i<y-1;i++)
{
cout<<(mst[i].x)+1<<" "<<(mst[i].y)+1<<" "<<mst[i].waga<<endl;	
	
}		
	
		
					

///////////////////////////////////////////////////////////////////////////////////////////////////////////

	return 0;
	system("PAUSE");
}
}

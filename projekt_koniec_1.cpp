#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <bits/stdc++.h> 

using namespace std;

void sort(long int tab[],int l)
{
	for(int p=0;p<l;p++)
		for(int j=1;j<l-p;j++)
		if(tab[j-1]>tab[j])
			swap(tab[j-1], tab[j]);
}

void ilosc(long int tab[], int liczba, int n)	{	// tab[] - posortowana tablica, 
	int p, l, s; 									// o iloœci elementów n
	long int ilosc=0;						
	l = 0;
	p = n-1;
	while (true)						
	{
	s = (l+p)/2;
	if (tab[s] == liczba)							//wyszukiawanie zadanej liczby
		{		
		for(long int e=n;e>0-n;e--){
			if(e != 0 ){
				if(tab[s] == tab[s+e]){				//sprawdzanie jej krotnoœci
				ilosc++;
				}
			}

		}	
			cout << "Odnaleziono liczbe " << liczba <<  ", " << ilosc <<" krotnie." << endl;

		break;
		}
	else if (tab[s] < liczba)
		l = s+1;
		else
			p = s-1;
	}
}

int main()
{
	time_t start, end;
	srand(time(NULL));
	int n=1000, g=1;
	start = time(0);
	cout << "Podaj dlugosc tablicy:";
	cin >> n;
    long int TABlica[n];
    

	for(int i=0;i<n;i++)	{
		
		TABlica[i]=(rand()%10) + 1 ;
	}
	
	cout<<"Tablica nieposortowana:"<<endl;
	for(int k=0;k<n;k++)	{
		cout << TABlica[k]<<"	";
	}
	
	cout<<endl;
	
   cout<<"Tablica posortowana"<<endl;
   
   sort(TABlica,n);
   
   for(int k=0;k<n;k++)	{
		cout << TABlica[k]<<"	";
	}
	
	cout << endl << "Szukana liczba: "<< endl;
	cin >> g;
	start = time(0);
	ilosc(TABlica, g, n);
	end = time(0);
	double czas = difftime(end, start);
    cout<<"Algorytm zajal: "<< fixed << czas << setprecision(50) << "sekund" << endl;
    
    return 0;
}

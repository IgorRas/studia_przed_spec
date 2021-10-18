#include <cstdlib>
#include <iostream>

//Sito Eratostenesa z dynamiczna alokacja pamieci

int main (int argc, char *argv[])	{
	int n = atoi(argv[1]);
	int s=0;
	int *p=(int*)std::malloc(n * sizeof(int));
	for (int j=2; j<n; j++)	{
		p[j]=1;	
	}
	for (int j=2; j<n; j++)	{
		for (int w=j+j; w<=n; w+=j)	{
			p[w]=0;
		}
	}
	for (int j=2; j<n; j++)	{
		if(p[j]==1)	{
			std::cout<<j<<" ";
		}
	}
	std::free(p);
}

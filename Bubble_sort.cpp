#include <iostream>

void swap(int *x1, int *x2)	{
	int x=*x1;
	*x1=*x2;
	*x2=x;
}

void bubble_sort(int t[], int n)	{
	bool u;
	do {
		u = false;
		for (int *i = t; i + 1 < t+n; ++i) {
			if (i[1] < i[0]) {
				swap(i, i+1);
				u = true; 
				}
			}
		}
	while (u);
}

int main()	{
	int t[] = {2,4,6,-1,0,2,10,7};
	
	bubble_sort(t+2, 4);
	
	for (int *i=t; i<t+8; i++)	{
		std::cout<<*i<<" ";
	}
}

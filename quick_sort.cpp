#include <iostream>
#include <vector>

void partition(std::vector<int>::iterator b, std::vector<int>::iterator e, int n)	{
	while(true)	{
	for(; *b<n && b<e ; b++);
	while(n<=*--e && b<e);
	if(b==e){
		return b;
	}
	std::iter_swap(b++, e);
	}
}

void quick_sort(std::vector<int>::iterator b, std::vector<int>::iterator e)	{
	if(b<e)	{
		auto i = partition(b, e-1, *(e-1));
		std::iter_swap(e-1,i);
		quick_sort(b,i);
		quick_sort(i+1,e);
	}
}

int main()	{
	std::vector<int> v{6,1,8,2,7,2,9,4,5};
	quick_sort(v.begin(), v.end());
	for (std::vector<int>::const_iterator i=v.cbegin(); i<v.cend(); i++)	{
		std::cout<<*i<<" ";
	}
	std::cout<<std::endl;
}

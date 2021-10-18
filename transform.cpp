#include <iostream>
#include <vector>
#include <functional>

std::vector<int>::iterator transform(std::vector<int>::const_iterator b, std::vector<int>::const_iterator e, std::vector<int>::iterator r, std::function<int(int)> p=[] (int element) {return element*element;})	{
	while (b<e)	{
		*r=p(*b);
		r++;
		b++;
	}
	return r;
}

int main()	{
	const std::vector<int> vector1 {-7, 5, 1, 2, 11};
	std::vector<int> vector2(5);
	auto result = transform(vector1.cbegin(), vector1.cend(), vector2.begin(),[](int element) {return element * element;});
	for (auto iterator = vector2.cbegin(); iterator < result;)	{
		std::cout<<*iterator++ <<" ";	
	}
	std::cout<<std::endl;
}



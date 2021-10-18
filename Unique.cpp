#include <iostream>
#include <vector>

std::vector<int>::iterator unique(std::vector<int>::iterator b, std::vector<int>::iterator e)	{
	auto t=b;
	while(b<e) {
       if(*b!=*(b+1)){
       		*t++=*b;
		}
		b++;
	}
	return t;
}

int main()	{
	std::vector<int> vector {-7, -7, 5, 2, 2, 2, 11, 2, 3, 3};
	auto result = unique(vector.begin(), vector.end());
	for (auto iterator = vector.cbegin(); iterator < result;)	{
		std::cout << *iterator++ << " ";
	}
	std::cout << std::endl;
}

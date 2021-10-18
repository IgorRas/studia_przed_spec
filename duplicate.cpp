#include <algorithm>
#include <iostream>
#include <vector>

//Wczytuje liczby
//Wypisuje powtarzajoce sie

std::vector<int> function1(std::vector<int> vector) {
	std::vector<int> koniec;	
	for (auto ite = vector.begin(); ite < vector.end(); ++ite) {
		std::vector<int>::iterator it, it1;
		it = std::adjacent_find(vector.begin(), vector.end());
		if(it!=vector.end()){
			it1 = std::find_if(koniec.begin(), koniec.end(), [it](int x) { return x==*it; } );
				if(it1==koniec.end()){
					koniec.push_back(*it);
			}
			vector.erase(it);
		}
	}
	return koniec;
}

int main () {
	int x;
	std::vector<int> numbers;
	for(;std::cin>>x;)
		numbers.push_back(x);
	std::sort(numbers.begin(), numbers.end());
	std::vector<int> koniec1 = function1(numbers);
	for (auto ite = koniec1.begin(); ite < koniec1.end(); ++ite)
		std::cout << *ite << ' ' ;
}

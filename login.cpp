#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>


int main() {
	std::set<int> pins;
	std::ifstream input("login.txt");
	for(int pin; input >> pin;) {
		pins.insert(pin);
	}
	input.close();
	
	int pin;
	std::cin >> pin;
	std::cout << std::boolalpha << (bool)pins.count(pin);//ten sposób ma ni¿sz¹ z³o¿onoœæ obliczeniow¹(logN) ni¿ std::count(N), bo ma wyszukiwanie binarne wbudowane 
}

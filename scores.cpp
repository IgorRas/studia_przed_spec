#include <iostream>
#include <map>
#include <string>

int main() {
	std::map<std::string, int> scores;
	int punkty;
	for(std::string nazwa; std::cin >> nazwa >> punkty;) {
		auto i = scores.find(nazwa);
		if(i == scores.end()) {
			scores[nazwa] = punkty;
		}
		else {
			scores[nazwa] = punkty + i->second;
		}
		
	}
	for(auto p: scores) {
		std::cout << p.first << " " << p.second << std::endl;
	}
}

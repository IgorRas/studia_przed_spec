/*
Zaimplementuj:
	�Operator+, po kt�rego obu stronach stoj� niemodyfikuj�ce referencje wektor�w liczb rzeczywistych,
	za� wynikiem jest nowy wektor zawieraj�cy wszystkie elementy wektora po lewej,
	a po nich wszystkie elementy wektora po prawej.
	
	�Operator+=, po kt�rego lewej i prawej stronie stoi odpowiednio modyfikuj�ca i niemodyfikuj�ca referencja wektora liczb rzeczywistych,
	a wynikiem jest modyfikuj�ca referencja wektora po lewej.
	Operator dopisuje na jego koniec wszystkie elementy wektora po prawej.

Operatory powinny by� przystosowane do u�ycia w przyk�adowym programie poni�ej. Operatory korzystaj� tylko z pliku nag��wkowego vector.

	Przyk�adowy program
int main() {
	std::vector<double> vector = std::vector<double> {6.7, -12.3} + std::vector<double> {-2.7, 19};
	(vector += std::vector<double> {0.5, -2.7}) += std::vector<double> {19};
	for (double element: vector) {
		std::cout << element << " "; }
	std::cout << std::endl; }
	
	Wykonanie
	Out: 6.7 -12.3 -2.7 19 0.5 -2.7 19
*/

#include <iostream>
#include <vector>

std::vector<double> operator +(const std::vector<double> &v1, const std::vector<double> &v2)	{
	std::vector<double> vc;
	vc.insert(vc.begin(), v1.begin(), v1.end());
	vc.insert(vc.end(), v2.begin(), v2.end());
	return vc;
}
std::vector<double> &operator += (std::vector<double> &v1, const std::vector<double> &v2)	{
	v1.insert(v1.end(), v2.begin(), v2.end());
	return v1;
}


int main() {
	std::vector<double> vector = std::vector<double> {6.7, -12.3} + std::vector<double> {-2.7, 19};
	(vector += std::vector<double> {0.5, -2.7}) += std::vector<double> {19};
	for (double element: vector)	{
		std::cout << element << " ";
	}
	std::cout << std::endl;
}


/*
n-ty wyraz ci�gu geometrycznego o wyrazie pocz�tkowym a0 oraz ilorazie q jest r�wny an = a0 * q^n.
Napisz klas� Geometric reprezentuj�c� ci�g geometryczny o zadanych parametrach a0 i q.
Zaimplementuj:
	�Konstruktor przyjmuj�cy a0 i q.
	�Sta�y operator[], kt�ry przyjmuje n i zwraca an.
Klasa powinna by� przystosowana do u�ycia w przyk�adowym programie poni�ej. Klasa korzysta tylko z pliku nag��wkowego cmath.
	Przyk�adowy program
int main() {
	const Geometric geometric(1., 0.5);
	std::cout << geometric[2] << std::endl; }
*/

#include <iostream>
#include <cmath>

class Geometric	{
	double a0, q;
	public:
		Geometric(double a0, double q);
		double operator [](const double n) const;
};

Geometric::Geometric(double a0, double q):a0(a0), q(q)	{}

double Geometric::operator [](const double n) const	{
	double an = Geometric::a0*(pow(Geometric::q, n));
	return an;
}

int main() {
	const Geometric geometric(1., 0.5);
	std::cout << geometric[2] << std::endl; 
}

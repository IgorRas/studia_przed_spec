/*
n-ty wyraz ci¹gu geometrycznego o wyrazie pocz¹tkowym a0 oraz ilorazie q jest równy an = a0 * q^n.
Napisz klasê Geometric reprezentuj¹c¹ ci¹g geometryczny o zadanych parametrach a0 i q.
Zaimplementuj:
	•Konstruktor przyjmuj¹cy a0 i q.
	•Sta³y operator[], który przyjmuje n i zwraca an.
Klasa powinna byæ przystosowana do u¿ycia w przyk³adowym programie poni¿ej. Klasa korzysta tylko z pliku nag³ówkowego cmath.
	Przyk³adowy program
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

#include <istream>
#include <ostream>
#include <iostream>


template <int N>
class Modulo {
	private:
		int x;
	public:
		Modulo():x(0) {};
		Modulo operator+(const Modulo& nowy) {
			Modulo temp;
			temp.x = x + nowy.x;
			return temp;
		};
		Modulo operator*(const Modulo& nowy1) {
			Modulo temp;
			temp.x = x * nowy1.x;
			return temp;
		};
		friend std::istream &operator>>(std::istream &input, Modulo &nowy) {
			input >> nowy.x;
			nowy.x = nowy.x % N;
			return input;
		}
		friend std::ostream &operator<<(std::ostream &output, Modulo nowy) {
			nowy.x = nowy.x % N;
			output << nowy.x;
			return output;
		}
		Modulo& operator++() {
			x++;
			return *this;
		}
		Modulo operator++(int) {
			Modulo temp = *this;
			++*this;
			return temp;
		}
		Modulo& operator--() {
			x--;
			return *this;
		}
		Modulo operator--(int) {
			Modulo temp = *this;
			--*this;
			return temp;
		}
};








int main() {
    Modulo<16> modulo1, modulo2;
    std::cin >> modulo1 >> modulo2;
    std::cout << modulo1 + modulo2 << " " << modulo1 * modulo2 << std::endl;
    std::cout << ++modulo1 << " " << modulo2++ << std::endl;
	}

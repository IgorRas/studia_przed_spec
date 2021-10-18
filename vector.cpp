#include <iostream>
#include <initializer_list>

template<typename E>
class vector {
public:
	vector();
	vector(std::initializer_list<E> l);
	E operator[](int i);
	int size();
	void push_back(E x);
private:
	int c, s;
	E *d;
};

template<typename E>
E vector<E>::operator[](int i) {
	return d[i];
}

template<typename E>
int vector<E>::size() {
	return s;
}

template<typename E>
void vector<E>::push_back(E x) {
	if(s == c) {
		c=(c ? 2 * c : 1);
		E *p = new int[c];
		for (int i =0; i < s; ++i) {
			p[i] = d[i];
		}
		delete[] d;
		d = p;
	}
	d[s++]=x;
}

template<typename E>
vector<E>::vector():c(), s(), d(){}

template<typename E>
vector<E>::vector(std::initializer_list<E> l):vector<E>() {
	for(E x:l) {
		push_back(x);
	}
}

int main() {
	vector<int> v{0, 6, -3, -6, 5, 2};
	for(int x; std::cin>>x;) {
		v.push_back(x);
	}
	for (int i=0; i< v.size();++i) {
		std::cout << v[i] << " ";
	}
}

#include <iostream> 

template<typename E>
void print(E t) {
	std::cout << t ;
}

template<typename T, typename... Args>
void print(T t, Args... args) // recursive variadic function
{
    std::cout << t <<" " ;

    print(args...) ;
}


int main() {
	print(1, 3.1415, "Hello");
}

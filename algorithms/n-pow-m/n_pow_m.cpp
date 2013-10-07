#include <iostream>

template<int N, int M> 
struct Pow {
    enum { value = N * Pow<N, M-1>::value };
};

template<int N>
struct Pow<N, 0> {
    enum { value = 1 };
};

int main() {
    std::cout << Pow<2, 10>::value << std::endl; 
    return 0;
}


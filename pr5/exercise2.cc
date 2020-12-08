#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector <int> vect(5);

    for (int i = 0; i < 5; i++) {
        std::cout << "Introduce un valor para el vector: ";
        std::cin >> vect[i];
        std::cout << std::endl;
    }

    for (int i = 0; i < 5; i++) {
        std::cout << "VECT[" << i << "] = " << vect[i] << std::endl;
    }

    std::cout << std::endl;
    std::sort(vect.begin(), vect.end());

    for (int i = 0; i < 5; i++) {
        std::cout << "VECT[" << i << "] = " << vect[i] << std::endl;
    }

    return 0;
}
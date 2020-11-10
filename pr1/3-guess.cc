#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {

    int i;
    srand(time(NULL));
    int key = rand() % 10+1;

    while(i != key) {
        std::cout << "Introduce el numero: ";
        std::cin >> i;
    }
    std::cout << "CORRECT THE KEY WAS: " << key;

    return 0; 
}
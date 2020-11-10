#include <iostream>

namespace n1 {
    int a;
    int b;
}

namespace n2 {
    int a;
    int c;
}

int main() {

    int a=55;
    n1::a=0;
    n2::a=2;
    std::cout << "n1::a= " << n1::a << "\n";
    std::cout << "n2::a= " << n2::a << "\n";
    std::cout << "a= " << a << "\n";

    return 0;
}
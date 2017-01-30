#include "Matrix.h"
#include <iostream>

int main(int argc, char* argv[])
{
//    for (int i = 1; i < argc; ++i) {
//        std::cout << argv[i] << std::endl;
//    }

    neox::Matrix a(2, 3);
    neox::Matrix b(5, 6);

    a[0][1] = 1;
    a[2][0] = 2;
    std::cout << a << std::endl;
    // a.transpose();
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    return 0;
}

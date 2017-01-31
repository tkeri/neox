#include "Matrix.h"
#include <iostream>

int main(int argc, char* argv[])
{

    neox::Matrix a(2, 3);

    a[0][0] = 3;
    a[0][1] = 1;
    a[1][0] = 8;
    std::cout << a << std::endl;

    a.transpose();

    std::cout << a << std::endl;

    return 0;
}

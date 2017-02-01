#include "Matrix.h"
#include <iostream>

int main(int argc, char* argv[])
{

    neox::Matrix a(4, 3);

    a[0][0] = 3;
    a[0][1] = 2;
    a[0][2] = 1;
    a[1][0] = 2;
    a[1][1] = 4;
    a[1][2] = 5;
    a[2][0] = 1;
    a[2][1] = 5;
    a[2][2] = 3;

    std::cout << a << std::endl;

    a.transpose();
    a.symmetry();

    std::cout << a << std::endl;

    if (a.symmetry() == true)
        std::cout << "a: Symmerty" << std::endl;
    else
        std::cout << "a: Not symmetry" << std::endl;

    return 0;
}

#include "Matrix.h"
#include <iostream>

int main(int argc, char* argv[])
{

    neox::Matrix a(3, 3);

    a[0][0] =  0;
//    a[0][1] = 2;
//    a[0][2] = 1;
//    a[1][0] = 2;
    a[1][1] = 0;
//    a[1][2] = 5;
//    a[2][0] = 1;
//    a[2][1] = 5;
    a[2][2] = a[0][0];

    std::cout << a << std::endl;

    a.transpose();

    std::cout << a << std::endl;

    return 0;
}

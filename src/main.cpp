#include "Matrix.h"
#include <iostream>

struct Pair {
    Pair(const int p = 0, const int f = 0) : pass(p), fail(f) {}
    int pass;
    int fail;
};

std::ostream& operator<<(std::ostream& os, const Pair& obj)
{
    os << "Pass: " << obj.pass << " Fail: " << obj.fail;
    return os;
}

Pair testEqual();
Pair testNotEqual();
Pair testSquare();
Pair testDiag();


void runTest()
{
    std::cout << "Test Equal: " << testEqual() << std::endl;
    std::cout << "Test Not-Equal: " << testNotEqual() << std::endl;
    std::cout << "Test Sqare: " << testSquare() << std::endl;
    std::cout << "Test Diag: " << testDiag() << std::endl;
}

int main(int argc, char* argv[])
{
    runTest();

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
    a.square();

    std::cout << a << std::endl;

    return 0;
}

// Tests

Pair testEqual()
{
    Pair stat;

    neox::Matrix R(3, 3);
    neox::Matrix nonR(2, 3);

    if (R == nonR)
        stat.fail++;
    else
        stat.pass++;

    neox::Matrix C(4, 4);
    neox::Matrix nonC(4, 1);

    if (C == nonC)
        stat.fail++;
    else
        stat.pass++;

    neox::Matrix A(1, 1);
    neox::Matrix nonA(1, 1);

    A[0][0] = 1;
    nonA[0][0] = 5;

    if (A == nonA)
        stat.fail++;
    else
        stat.pass++;

    neox::Matrix B(1, 2);
    neox::Matrix eqB(1, 2);

    B[0][0] = 1;
    B[0][1] = 2;
    eqB[0][0] = 1;
    eqB[0][1] = 2;

    if (B == eqB)
        stat.pass++;
    else
        stat.fail++;

    return stat;
}

Pair testNotEqual()
{
    Pair stat;

    neox::Matrix R(3, 3);
    neox::Matrix eqR(3, 3);

    if (R != eqR)
        stat.fail++;
    else
        stat.pass++;

    neox::Matrix C(4, 4);
    neox::Matrix eqC(4, 4);

    if (C != eqC)
        stat.fail++;
    else
        stat.pass++;

    neox::Matrix A(1, 1);
    neox::Matrix eqA(1, 1);

    A[0][0] = 1;
    eqA[0][0] = 1;

    if (A != eqA)
        stat.fail++;
    else
        stat.pass++;

    neox::Matrix B(1, 2);
    neox::Matrix nonB(1, 2);

    B[0][0] = 1;
    B[0][1] = 2;
    nonB[0][0] = 1;
    nonB[0][1] = 56;

    if (B != nonB)
        stat.pass++;
    else
        stat.fail++;

    return stat;
}

Pair testSquare()
{
    Pair stat;

    neox::Matrix S(3, 3);

    if (S.square())
        stat.pass++;
    else
        stat.fail++;

    neox::Matrix nonS(3, 2);

    if (nonS.square())
        stat.fail++;
    else
        stat.pass++;

    return stat;
}

Pair testDiag()
{
    Pair stat;

    neox::Matrix Diag(2, 2);

    Diag[0][0] = 1;
    Diag[0][1] = 0;
    Diag[1][0] = 0;
    Diag[1][1] = 2;

    if (Diag.diag())
        stat.pass++;
    else
        stat.fail++;

    neox::Matrix nonDiag(2, 2);

    nonDiag[0][0] = 1;
    nonDiag[0][1] = 1;
    nonDiag[1][0] = 1;
    nonDiag[1][1] = 1;

    if (nonDiag.diag())
        stat.fail++;
    else
        stat.pass++;

    return stat;
}

#include <iostream>

void fiddle(int in1, int &in2)
{
    in1 = 2;
    in2 = 8848;
    std::cout << "[Fuction] In1: " << in1 << " In2: " << in2 << std::endl;
}

int main(int argc, char *argv[])
{
    int in1 = atoi(argv[1]);
    int in2 = atoi(argv[2]);
    std::cout << "[Before ] In1: " << in1 << " In2: " << in2 << std::endl;
    fiddle(in1, in2);
    std::cout << "[After  ] In1: " << in1 << " In2: " << in2 << std::endl;
}
#include <iostream>

unsigned long int combination(unsigned int n, unsigned int k)
{

    if (n < k)
    {
        std::cerr << "n must be larger than k" << std::endl;
        exit(-1);
    }

    if ((k == 0) || (n == k))
    {
        return 1;
    }

    return combination(n - 1, k) + combination(n - 1, k - 1);
}

int main(int argc, char *argv[])
{
    unsigned int n = atoi(argv[1]);
    unsigned int k = atoi(argv[2]);

    if (n < k)
        std::swap(n, k);

    std::cout << "C("<<n<<","<<k<<")="<<combination(n,k)<<std::endl;
}
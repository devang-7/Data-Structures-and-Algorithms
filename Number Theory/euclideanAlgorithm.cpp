#include <iostream>
#include "classSolution.cpp"
using namespace std;
int Solution::gcd(int a, int b)
{
    if (b == 0)
        return a;
        
    return gcd(b,a%b);
}


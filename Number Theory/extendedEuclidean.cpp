#include "classSolution.cpp"

int Solution::extendedGcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x=1;
        y=0;
        return a;
    }

    int x1,y1,d;
    d=extendedGcd(b,a%b,x1,y1);
    x= y1;
    y= x1 - y1*(a/b);
    return d;                   //d is the gcd of a and b
}


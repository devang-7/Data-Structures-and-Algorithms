/******************************************
*  Author : ${DEVANG}   
*  Created On : Sun Apr 25 2021
*  File : ${*.CPP}
*******************************************/
#include "classSolution.cpp"

    int Solution:: modifiedPrimeFactorization(int n)
    {
        int answer =1, temp =0;
        while (n % 2 == 0)
            n = n / 2;

        for (int i = 3; i <= sqrt(n); i += 2)
        {
            temp = 0;
            while(n % i == 0)
            {
                temp++;
                n=n/i;
            }
            answer*=(temp+1);
        }
        temp = 1;
        if(n>2)
            temp*=2;
        answer*=temp;
        return answer;    
    }

int Solution::politeness(int n)
{
    return modifiedPrimeFactorization(n) - 1;
}

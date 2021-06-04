/******************************************
*  Author : ${DEVANG}   
*  Created On : Sat Apr 24 2021
*  File : ${*.cpp}
*******************************************/

#include "classSolution.cpp"
    
    vector<int> Solution:: primeFactorization(int n)
    {
        vector<int> answer;
        while (n % 2 == 0)
        {
            answer.push_back(2);
            n = n / 2;
        }

        for (int i = 3; i <= sqrt(n); i += 2)
        {
            while(n % i == 0)
            {
                answer.push_back(i);
                n = n / i;
            }
        }

        if(n>2)
            answer.push_back(n);

        return answer;    
    }

    int Solution:: sumOfVector(vector<int> arr)
    {
        int sum = 0;
        for(int i: arr)
            sum+=i;
        return sum;
    }    

    
/******************************************
*  Author : ${DEVANG}   
*  Created On : Sun Apr 25 2021
*  File : ${*.CPP}
*******************************************/
#include<bits/stdc++.h>


using namespace std;
class Solution{
    public:

    //To compute gcd; constraints: a>b
    int gcd(int a, int b);

    //To generate an array of all the prime factors of an element
    vector<int> primeFactorization(int n);

    //To generate the sum of an entire array
    int sumOfVector(vector<int> arr);

    //To compute x and y of the eqn a.x + b.y = gcd 
    int extendedGcd(int a, int b, int &x, int &y);

    //To compute the politeness of a number
    int modifiedPrimeFactorization(int n);          //returns power of the prime factors with +1
    int politeness(int n);                          //computes the number of ways 'n' can be expressed as the sum of consecutive integers.

};

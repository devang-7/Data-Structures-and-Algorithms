#include<bits/stdc++.h>

using namespace std;

int isArraySorted(int A[], int n)
{
    if(n==1)
        return 1;

    return A[n-1] < A[n-2]?0:isArraySorted(A, n-1);    
}

int main()
{
    int A[4] = {2,3,4,1};
    cout<<isArraySorted(A,4);
}
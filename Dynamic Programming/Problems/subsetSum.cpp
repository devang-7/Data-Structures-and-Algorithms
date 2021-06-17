#include <bits/stdc++.h>

using namespace std;

#define maxN 100
#define maxW 1000

bool subsetSum(vector<int> arr, int n, int sum)
{
    static bool t[maxN][maxW];

    int i = 0;
    for (int j = 0; j < sum + 1; j++)
    {
        t[i][j] = false;
    }

    int j = 0;
    for (int i = 0; i < n + 1; i++)
    {
        t[i][j] = true;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][sum];
}
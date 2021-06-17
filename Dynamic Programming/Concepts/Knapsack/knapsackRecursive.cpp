#include <iostream>
#include <vector>
using namespace std;

#define maxN 100
#define maxW 1000

class Solution
{

    int knapsackRecursive(vector<int> wt, vector<int> val, int n, int capacity)
    {
        if (n == 0 || capacity == 0)
            return 0;

        else if (wt[n - 1] <= capacity)
            return max((wt[n - 1] + knapsackRecursive(wt, val, n - 1, capacity - wt[n - 1])), knapsackRecursive(wt, val, n - 1, capacity));

        else
            return knapsackRecursive(wt, val, n - 1, capacity);
    }

    int knapsackMemoized(vector<int> wt, vector<int> val, int n, int capacity)
    {
        //Created a matrix and initialised it with -1
        static int t[maxN][maxW];
        memset(t, -1, sizeof(t));

        if (n == 0 || capacity == 0)
            return 0;

        //If matrix contains a value other than -1, then it returns the value and comes out of the function call
        if (t[n][capacity] != -1)
            return t[n][capacity];

        else if (wt[n - 1] <= capacity)
            return t[n][capacity] = max((wt[n - 1] + knapsackRecursive(wt, val, n - 1, capacity - wt[n - 1])), knapsackRecursive(wt, val, n - 1, capacity));

        else if (wt[n - 1] > capacity)
            return t[n][capacity] = knapsackRecursive(wt, val, n - 1, capacity);
    }

    int bottomUp(vector<int> wt, vector<int> val, int n, int capacity)
    {
        static int t[maxN][maxW];
        
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < capacity + 1; j++)
            {
                if (i == 0 || j == 0)
                    t[i][j] = 0;
            }
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < capacity + 1; j++)
            {
                if (wt[i - 1] <= j)
                    t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
                else
                    t[i][j] = t[i - 1][j];
            }      
        }
        return t[maxN][maxW];
    }
};

int main()
{
    return 0;
}

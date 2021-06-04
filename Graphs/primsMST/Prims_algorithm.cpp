#include <iostream>

using namespace std;

int cost[8][8] = {
    {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
    {INT_MAX, INT_MAX, 25, INT_MAX, INT_MAX, INT_MAX, 5, INT_MAX},
    {INT_MAX, 25, INT_MAX, 12, INT_MAX, INT_MAX, INT_MAX, 10},
    {INT_MAX, INT_MAX, 12, INT_MAX, 8, INT_MAX, INT_MAX, INT_MAX},
    {INT_MAX, INT_MAX, INT_MAX, 8, INT_MAX, 16, INT_MAX, 14},
    {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 16, INT_MAX, 20, 18},
    {INT_MAX, 5, INT_MAX, INT_MAX, INT_MAX, 20, INT_MAX, INT_MAX},
    {INT_MAX, INT_MAX, 10, INT_MAX, 14, 18, INT_MAX, INT_MAX},
};

int near[8] = {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX};
int t[2][6];

int main()
{

    int i, j, k, u, v, n = 7, minElement = INT_MAX;

//Manually selecting the minimum element from the adjacency matrix
    for (i = 1; i <= n; i++)
    {
        for (j = i; j <= n; j++)
        {
            if (cost[i][j] < minElement)
            {
                u = i;
                v = j;
                minElement = cost[i][j];
            }
        }
    }


//Setting the edges matrix to u and v
    t[0][0] = u;
    t[1][0] = v;

//Setting the near matrix for u and v ==> 0
    near[u] = 0;
    near[v] = 0;

//Setting other variables; Comparing each variable with u and v
    for (int i = 1; i <= n; i++)
    {
        if(near[i]!=0)
        {
            if(cost[i][u] < cost[i][v] )
                near[i] = u;
            else near[i] = v;
        } 
    }


//Looping and repeating the above process 
    for(i=1; i<n-1; i++)
    {
        minElement = INT_MAX;

        for(j=1; j<=n; j++)
        {
            if(near[j]!=0 && cost[j][near[j]] < minElement )
            {
                minElement = cost[j][near[j]];
                k = j;
            }
        }

        t[0][i] = k;
        t[1][i] = near[k];
        near[k] = 0;

        for(j = 1; j<=n; j++)
        {
            if(near[j]!=0 && cost[j][near[j]] > cost[j][k] )
                near[j] = k;
        }


    }


//Printing the edges matrix
    for(int i = 0; i<2; i++)
    {
        for(int j = 0; j<6; j++ )
        {
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}
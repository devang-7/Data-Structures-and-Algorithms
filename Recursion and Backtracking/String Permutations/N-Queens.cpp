#include <bits/stdc++.h>

using namespace std;

vector<vector<string> > vec;

bool isSafe(int **arr, int x, int y, int n)
{
    //Horizontal
    for (int row = 0; row < x; row++)
    {
        if (arr[row][y] == 1)
            return false;
    }

    //Left Diagonal
    int r = x - 1;
    int c = y - 1;

    while (r >= 0 && c >= 0)
    {
        if (arr[r][c] == 1)
            return false;
        r--;
        c--;
    }

    //Right Diagonal
    r = x;
    c = y;

    while (r >= 0 && c < n)
    {
        if (arr[r][c] == 1)
            return false;
        r--;
        c++;
    }

    return true;
}

void nQueenUtil(int **arr, int x, int n)
{
    if (x >= n)
    {
        vector<string> tempAnswer;
        for (int i = 0; i < n; i++)
        {
            string temp;
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j])
                    temp += "Q";
                else
                    temp += ".";
            }
            tempAnswer.push_back(temp);
        }
        vec.push_back(tempAnswer);
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(arr, x, col, n))
        {
            arr[x][col] = 1;
            nQueenUtil(arr, x + 1, n);
            arr[x][col] = 0;
        }
    }
    return;
}

int main()
{
    int n;
    cin >> n;

    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
            arr[i][j] = 0;
    }

    nQueenUtil(arr, 0, n);
    for(auto it: vec)
    {
        for(auto i: it)
        {
            cout<<i<<' ';
        }
        cout<<endl;
    }

    return 0;
}
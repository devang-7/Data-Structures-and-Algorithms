#include <bits/stdc++.h>

using namespace std;


vector<int> temp{3, 3, 3, 3,4};
int c = 0;
void partitions(int i, int n, int k, int nos, vector<vector<int> > answer)
{
    if (i > n)
    {
        if (nos == k)   
        {
            c++;
            for (auto i : answer)
            {
                cout << "[";
                for (auto it : i)
                {
                    cout << it;
                }
                cout << "] ";
                cout << " ";
            }
            cout << endl;
        }
        return;
    }

    for (int j = 0; j < answer.size(); j++)
    {
        if (answer[j].size() > 0)
        {
            answer[j].push_back(temp[i]);
            partitions(i + 1, n, k, nos, answer);
            answer[j].pop_back();
        }
        else
        {
            answer[j].push_back(temp[i]);
            partitions(i + 1, n, k, nos + 1, answer);
            answer[j].pop_back();
            break;
        }
    }
}

int main()
{
    int k = 4, n = 4;

    vector<vector<int> > ans(k);
    int idx = 0;
    partitions(idx, n, k, 0, ans);
    cout<<"\n"<<c;
}
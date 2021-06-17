#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

void generatePermutations(int currState, int totalState, string asf, unordered_map<char, int> umap)
{
    if(currState > totalState)
    {
        cout<<asf<<endl;
        return;
    }


    for (auto i : umap)
    {
        if (i.second > 0)
        {
            umap[i.first] -=1;
            generatePermutations(currState+1, totalState, asf+i.first, umap);
            umap[i.first] +=1;
        }
    }
}
int main()
{
    unordered_map<char, int> umap;

    string s = "abc";

    for (auto t : s)
        umap[t] += 1;


    string asf;
    generatePermutations(0, s.size()-1, asf, umap);
}

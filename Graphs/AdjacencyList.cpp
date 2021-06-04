#include <iostream>
#include <list>
#include<bits/stdc++.h>

using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int x, int y)
    {
        l[x].push_back(y);
    }

    void printList(map<int,string> mp)
    {
        for(int i=0;i<V;i++)
        {
            // cout<<mp[i];
            if(l[i].size()<1)
               cout<<mp[i];
        }
    }
};

int main()
{
    Graph G(4);
    

}

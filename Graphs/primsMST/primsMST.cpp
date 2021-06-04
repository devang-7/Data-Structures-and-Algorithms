#include <bits/stdc++.h>
using namespace std;


int main()
{

    int n, m;   //n nodes and m edges
    cin >> n >> m;
    vector<pair<int, int> > adj[n];

    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back(make_pair(v, wt));
        adj[v].push_back(make_pair(u, wt));
    }

    int key[n], parent[n];
    bool vis[n];

    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        vis[i] = false;
        parent[i] = -1;
    }
    cout<<"Enter Source from where you want to start traversal ";
    int src;
    cin>>src;
    key[src] = 0;
    parent[src] = -1;
    int cost = 0;
    //Iterating to n-1 because we need n-1 edges
    for(int count =0; count<n-1; ++count)
    {
        int mini = INT_MAX, u;

        //Finding the minimum element in the key
        for(int v = 0; v<n; v++){
            if(vis[v]==false && key[v] < mini )
            {
                mini = key[v];
                u=v;
            }
        }

        vis[u] = true;


        //Iterating for all the adjacent nodes of u
        for(auto it: adj[u])
        {
            int v = it.first;
            int weight = it.second;

            if(vis[v]==false && key[v] > weight)
                {
                    parent[v] = u;
                    key[v] = weight;    
                    cost+=weight;
                }
        }
    }

    for(int i=0; i <n; i++)
    {   
        if(parent[i]!=-1)
            cout<<parent[i]<<"-->"<<i<<endl;
    }

    cout<<"\n"<<cost;
    return 0;
}
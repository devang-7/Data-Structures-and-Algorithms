#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, m; //n nodes and m edges
    cin >> n >> m;
    vector<pair<int, int> > adj[n];

    //Creating graph in form of adjacency list
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back(make_pair(v, wt));
        adj[v].push_back(make_pair(u, wt));
    }


    //Here, array 'key' is weight-index structure, parent stores the parent of the ith index and mstSet checks if a node is visited or not.
    int key[n], parent[n];
    bool mstSet[n];

    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
        parent[i] = -1;
    }

    cout << "Enter Source from where you want to start traversal ";
    int src;
    cin >> src;

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    key[src] = 0;
    parent[src] = -1;
    pq.push(make_pair(0,src));          //first-> wt ..... second->index
    int cost = 0;
    //Iterating to n-1 because we need n-1 edges
    for (int count = 0; count < n - 1; ++count)
    {
    
        int u = pq.top().second;
        pq.pop();

        mstSet[u] = true;

        //Finding the minimum element in the key
        for (auto it: adj[u])
        {
            int v = it.first;
            int weight = it.second;
            if(mstSet[v]==false && weight<key[v])
            {
                parent[v] = u;
                key[v] = weight;
                pq.push(make_pair(key[v],v));
                cost+=weight;
            }
        }

    }

    for (int i = 0; i < n; i++)
    {
        if (parent[i] != -1)
            cout << parent[i] << "-->" << i << endl;
    }

    cout <<"Cost->"<<cost;
    return 0;
}
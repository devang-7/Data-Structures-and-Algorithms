#include <bits/stdc++.h>

using namespace std;

class Graph
{
public:
    int V;
    int E;

    int **Adj;
    void print();
    void breadthFirstSearch(int i);
    void depthFirstSearch(int i);
    Graph* adjMatrixGraph()
    {
        int i, u, v;
        Graph *G = new Graph();

        cout << "Vertices and edges: ";

        cin>>G->V;
        cin>>G->E;

        G->Adj = new int*[G->V];

        for (int i = 0; i < G->V; ++i)
            G->Adj[i] = new int[G->V];

        for (u = 0; u < G->V; u++)
        {
            for (v = 0; v < G->V; v++)
                G->Adj[u][v] = 0;
        }

        // int node1, node2;
        // for (int i = 0; i < G->E; i++)
        // {
        //     cout << "Enter node1 and node2"
        //          << " ";
        //     cin >> node1 >> node2;
        //     G->Adj[node1][node2] = 1;
        //     G->Adj[node2][node1] = 1;
        //     cout << "\n";
        // }

        G->Adj[1][2] = 1;
        G->Adj[2][1] = 1;
        G->Adj[1][3] = 1;
        G->Adj[3][1] = 1;
        G->Adj[1][4] = 1;
        G->Adj[4][1] = 1;
        G->Adj[2][3] = 1;
        G->Adj[3][2] = 1;
        G->Adj[3][5] = 1;
        G->Adj[5][3] = 1;
        G->Adj[4][5] = 1;
        G->Adj[5][4] = 1;
        G->Adj[5][6] = 1;
        G->Adj[6][5] = 1;
        G->Adj[6][7] = 1;
        G->Adj[7][6] = 1;
        G->Adj[3][4] = 1;
        G->Adj[4][3] = 1;
        



        return G;
    }

    
    
};

void Graph::print()
{
    for (int i = 0; i < this->V; i++)
    {
        for (int j = 0; j < this->V; j++)
        {
            cout << this->Adj[i][j] << " ";
        }
        cout << "\n";
    }
}

// int main()
// {

//     Graph* temp = new Graph;
//     temp = adjMatrixGraph();

// }

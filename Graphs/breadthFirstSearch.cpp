#include "AdjacencyMatrix.cpp"

void Graph:: breadthFirstSearch(int i) //Here is the initial vertex
{
    queue<int> q;
    vector<int> visited(this->V,0);

    int u;
    cout<<i<<' ';

    visited[i] = 1;
    q.push(i);
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(int itr=1; itr< this->V; itr++)
        {
            if(this->Adj[u][itr]==1 && visited[itr]==0)
                {
                    cout<<itr<<" ";
                    visited[itr] = 1;
                    q.push(itr);
                }
        }
    }
}

int main()
{
    Graph *G = new Graph();
    G = G->adjMatrixGraph();
    G->print();
    cout<<endl;
    G->breadthFirstSearch(2);
    
}
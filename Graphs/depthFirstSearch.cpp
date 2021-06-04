#include "AdjacencyMatrix.cpp"

static int visited[8] = {0,0,0,0,0,0,0};

void Graph:: depthFirstSearch(int u)
{
    
    int itr;

    if (visited[u] == 0)
    {
        cout << u << " ";
        visited[u] = 1;
        for (itr = 1; itr < this->V; itr++)
        {
            if (this->Adj[u][itr] == 1 && visited[itr] == 0)
                depthFirstSearch(itr);
        }
    }
}

int main()
{
    Graph *G = new Graph();
    G = G->adjMatrixGraph();


    G->print();
    G->depthFirstSearch(4);
}
#include <iostream>
#include <string>
#include <unordered_map>
#include <list>

using namespace std;

int main()
{
    int vertices, edges;
    string v1, v2;

    printf("Enter the Number of Vertices -\n");
    cin >> vertices;

    printf("Enter the Number of Edges -\n");
    cin >> edges;

    // Adjacency List is a map of <string, list>.
    // Where each element in the list is pair<string, int>
    // pair.first -> the edge's destination (string)
    // pair.second -> edge's weight
    unordered_map<string, list<string> > adjacencyList(vertices + 1);

    printf("Enter the Edges V1 -> V2\n");
    for (int i = 1; i <= edges; ++i)
    {
        cin >> v1 >> v2;

        // Adding Edge to the Directed Graph
        adjacencyList[v1].push_back(v2);
    }

    // Printing Adjacency List
    cout << endl
         << "The Adjacency List-" << endl;
    // for (auto &value : adjacencyList)
    // {
    //     string vertex = value.first;
    //     list<string> adjacentVertices = value.second;
    //     list<string>::iterator itr = adjacentVertices.begin();

    //     cout << "adjacencyList[" << vertex << "]";

    //     while (itr != adjacentVertices.end())
    //     {
    //         cout << " -> " << (*itr) ;
    //         ++itr;
    //     }

    //     cout << endl;
    // }

    cout << endl;
    return 0;
}

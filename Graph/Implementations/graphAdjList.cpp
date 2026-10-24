
#include <iostream>
#include <vector>
using namespace std;

class Graph
{
    int V;
    vector<int> adj[100];

public:
    Graph(int vertices)
    {
        V = vertices;
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    void display()
    {
        cout << "Adjacency List:" << endl;

        for (int i = 0; i < V; i++)
        {
            cout << i << " -> ";

            for (int neighbor : adj[i])
            {
                cout << neighbor << " ";
            }

            cout << endl;
        }
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    g.display();

    return 0;
}

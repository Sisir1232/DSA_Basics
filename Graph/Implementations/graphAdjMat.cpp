
#include <iostream>
using namespace std;

class Graph
{
    int V;
    int matrix[100][100];

public:
    Graph(int vertices)
    {
        V = vertices;

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v)
    {
        matrix[u][v] = 1;
        matrix[v][u] = 1; // Undirected graph
    }

    void display()
    {
        cout << "Adjacency Matrix:" << endl;

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                cout << matrix[i][j] << " ";
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

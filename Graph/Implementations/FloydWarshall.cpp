// Implementation of floyd warshall algorithm to find shortest distance between every pair of vertices 
//  Key sight: compare direct and indirect path keeping (k=0-v) as intermediate node for ever pair 
// Dynamic Programming (DP) algorithm because it solves the problem by breaking it into smaller subproblems and reusing their results.

#include <iostream>
using namespace std;

const int INF = 1000000000;// (billion as infinite )

class Graph
{
    int V;
    int dist[100][100];// works as adjacency matrix too 

public:
    Graph(int vertices)
    {
        V = vertices;

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (i == j)
                    dist[i][j] = 0;
                else
                    dist[i][j] = INF;
            }
        }
    }

    void addEdge(int u, int v, int weight)
    {
        dist[u][v] = weight;  // directed graph ( u->v)
    }
    void floydWarshall()
    {
        // k is the intermediate vertex
        for (int k = 0; k < V; k++)
        {
            for (int i = 0; i < V; i++)
            {
                for (int j = 0; j < V; j++)
                {
                    if (dist[i][k] != INF &&       // extra condition is necessary for -ve weight 
                        dist[k][j] != INF &&
                        dist[i][k] + dist[k][j] < dist[i][j])
                    {
                        dist[i][j] =
                            dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        cout << "Shortest Distance Matrix:" << endl;

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][j] == INF)
                    cout << "INF ";
                else
                    cout << dist[i][j] << " ";
            }

            cout << endl;
        }
    }
};

int main()
{
    Graph g(4);

    g.addEdge(0, 1, 5);
    g.addEdge(0, 3, 10);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 0, 2);

    g.floydWarshall();

    return 0;
}
// This algorithm works for finding shortest distance between every pair of vertices 
// in directed / undirected  +ve weighted / -ve weighted graph 
// does not work for -ve weighted cycle 
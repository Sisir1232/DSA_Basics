
#include <iostream>
#include <queue>
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

    // DFS using recursion
    void DFS(int vertex, bool visited[])
    {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int i = 0; i < V; i++)
        {
            if (matrix[vertex][i] == 1 && !visited[i])
            {
                DFS(i, visited);
            }
        }
    }

    void startDFS(int start)
    {
        bool visited[100] = {false};

        cout << "DFS: ";
        DFS(start, visited);
        cout << endl;
    }

    // BFS using queue
    void BFS(int start)
    {
        bool visited[100] = {false};
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS: ";

        while (!q.empty())
        {
            int vertex = q.front();
            q.pop();

            cout << vertex << " ";

            for (int i = 0; i < V; i++)
            {
                if (matrix[vertex][i] == 1 && !visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }

        cout << endl;
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    g.startDFS(0);
    g.BFS(0);

    return 0;
}

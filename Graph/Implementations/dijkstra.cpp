// Implementation of dijkstra's algorithm to find shortest distance from single node 
// Key insight: use dist array to find minimum distance based on wt and use relaxation edge on every BFS traversal from src 
//            : min heap priority queue is needed to pop the least distance element after each relaxation

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Graph
{
    int V;
    vector<pair<int, int>> adj[100]; // array of vector containing neighboring vertices and weight

public:
    Graph(int vertices)
    {
        V = vertices;
    }

    void addEdge(int u, int v, int weight)
    {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight}); // Undirected graph
    }

    void dijkstra(int start)
    {
        int dist[100];

        for (int i = 0; i < V; i++)
            dist[i] = INT_MAX;      // initally distance is infinite 

        // Stores {distance, vertex}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        dist[start] = 0;
        pq.push({0, start});   // must be stored in ( dist ,V) order since pq sort according to first parameter

        while (!pq.empty())
        {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            // Ignore outdated entries
            if (d > dist[u])
                continue;

            // Relax all adjacent edges
            for (auto edge : adj[u])
            {
                int v = edge.first;
                int weight = edge.second;

                if (dist[u] + weight < dist[v])      // edge relaxation 
                {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Shortest distances from vertex "
             << start << ":" << endl;

        for (int i = 0; i < V; i++)
        {
            cout << start << " -> " << i << " : ";

            if (dist[i] == INT_MAX)
                cout << "Unreachable";
            else
                cout << dist[i];

            cout << endl;
        }
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 4, 3);
    g.addEdge(3, 4, 1);

    g.dijkstra(0);

    return 0;
}
// This algorithm may not necessarily work for -ve weighted graph 
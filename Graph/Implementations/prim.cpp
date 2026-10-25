// Implementation of prim algorithm to find minmum spanning tree in connected , weighted undirected graph 
//  spanning tree : subset of graph containing V vertices and V-1 edges
// Key insight: pick one node put it in queue  ,  pop , check its neighbor , select the neighbor with min weight , repeat 
//            : priority queue to store the neighbor with weights and pick the smallest one 
//            : visited boolean array to check whether the choosen one has already been used or not 

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
    int V;
    vector<pair<int, int>> adj[100];

public:
    Graph(int vertices)
    {
        V = vertices;
    }

    void addEdge(int u, int v, int weight)
    {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    void prim(int start)
    {
        // {weight, vertex}
        // vector<pair<int, int>>,greater<pair<int, int>> is used as parameter to make min heap 
                       
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        bool visited[100] = {false};
        int totalWeight = 0;

        pq.push({0, start});

        cout << "Prim's MST:" << endl;

        while (!pq.empty())
        {
            int weight = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (visited[u])
                continue;

            visited[u] = true;
            totalWeight += weight;

            if (weight != 0)
                cout << "Vertex " << u
                     << " added with edge weight "
                     << weight << endl;

            for (auto edge : adj[u])   // auto lets comipler decides the data type 
            {
                int v = edge.first;
                int w = edge.second;

                if (!visited[v])
                    pq.push({w, v});
            }
        }

        cout << "Total weight: " << totalWeight << endl;
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    g.prim(0);

    return 0;
}

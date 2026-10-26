// Implementation of kruskal algotithm to find MST 
// Key insight: choose the edge with minimum weight and if it form cycle , go to next 
//            : disjoint set data structure helps to find cycle 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_V 100

struct Edge
{
    int u;
    int v;
    int w;

    // operator overloading: Lets sort() compare edges by weight with no extra argument
    bool operator<(const Edge &other) const
    {
        return w < other.w;
    }
};

// Disjoint set (union-find) arrays
int parent[MAX_V]; // entity to represent the entire set 
int rnk[MAX_V];   // acts as height of a tree to determine which set merges to which 

void makeSet(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rnk[i] = 0;
    }
}

//  point every node on the path straight to the root
int findSet(int x)
{
    if (parent[x] != x)
    {
        parent[x] = findSet(parent[x]);  // recursion to find the parent of a parent 
    }
    return parent[x];
}

// Union by rank: attach the shorter tree under the taller one
// Returns false if both are already in the same set (edge would form a cycle)
bool unionSet(int a, int b)
{
    int ra = findSet(a);  // representation of a 
    int rb = findSet(b);  // representation of b 

    if (ra == rb)
    {
        return false;
    }

    if (rnk[ra] < rnk[rb])
    {
        parent[ra] = rb;
    }
    else if (rnk[ra] > rnk[rb])
    {
        parent[rb] = ra;
    }
    else
    {
        parent[rb] = ra;
        rnk[ra]++;
    }
    return true;
}

void kruskal(vector<Edge> &edges, int V)
{
    Edge mst[MAX_V];
    int count = 0;
    int total = 0;

    makeSet(V);

    // Greedy step: process edges from lightest to heaviest (uses Edge::operator<)
    sort(edges.begin(), edges.end());

    for (const Edge &e : edges)
    {
        // Take the edge only if it joins two different components
        if (unionSet(e.u, e.v))
        {
            mst[count] = e;
            count++;
            total += e.w;
        }

        // A spanning tree of V vertices has exactly V-1 edges, so stop early
        if (count == V - 1)
        {
            break;
        }
    }

    // If fewer than V-1 edges were picked, the graph is disconnected
    if (count != V - 1)
    {
        cout << "Graph is disconnected, no spanning tree exists" << endl;
        return;
    }

    cout << "Edges in MST:" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << mst[i].u << " - " << mst[i].v << " : " << mst[i].w << endl;
    }
    cout << "Total weight = " << total << endl;
}

int main()
{
    int V = 6;

    vector<Edge> edges = {
        {0, 1, 4},
        {0, 2, 4},
        {1, 2, 2},
        {1, 3, 5},
        {2, 3, 8},
        {2, 4, 10},
        {3, 4, 2},
        {3, 5, 6},
        {4, 5, 3}
    };

    kruskal(edges, V);
    return 0;
}
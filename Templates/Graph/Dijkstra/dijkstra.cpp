
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Dijkstra
{

public:
    int v, INF = -1;
    // Adjacency list/vector
    map< T, vector < pair < T, int > > > adj;

    // To establish a connection between nodes u and v with wt weighted edge.
    void addEdge(T u, T v, int wt, bool bidir = true)
    {
        adj[u].push_back(make_pair(v, wt));

        if (bidir) adj[v].push_back(make_pair(u, wt));
    }

    void dijkstraAlgo(T srcNode) 
    {
        map < T, int > dist;
        for (auto i = adj.begin(); i != adj.end(); i++)
            dist[i->first] = INF;

        dist[srcNode] = 0;
    }
   

};
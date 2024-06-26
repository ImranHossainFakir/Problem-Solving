
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

    map < T, int > dijkstraAlgo(T srcNode) 
    {
        map < T, int > dist;
        for (auto i = adj.begin(); i != adj.end(); i++)
            dist[i->first] = INF;

        dist[srcNode] = 0;
        set < pair < int, T > > s;
        s.insert(make_pair(0, srcNode));

        while (!s.empty())
        {
            auto node = *(s.begin());
            s.erase(s.begin());
            T parent = node.second;
            int parDist = node.first;

            for (auto i = adj[parent].begin(); i != adj[parent].end(); i++)
            {
                T child = i->first;
                if (dist[child] == INF || parDist + i->second < dist[child])
                {
                    auto f = s.find(make_pair(dist[child], child));
                    if(f != s.end()){
                        s.erase(f);
                    }
                    dist[child] = parDist + i->second;
                    s.insert(make_pair(dist[child], child));
                }
            }
        }
        return dist;
    }
};
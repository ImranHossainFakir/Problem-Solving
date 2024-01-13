

/*

Problem link: https://cses.fi/problemset/task/1195/
Time Complexity: O((n+m) log m) where n is nodes and m is edges.

*/


#include<bits/stdc++.h>

using namespace std;
#define int long long
#define endl "\n" 
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 9, INF = -1;

struct Node
{       
    int at, c;
};

struct CompareNode
{
    bool operator()(const Node &a, const Node &b) const
    {
        // Priority queue returns the smallest value.
        // So we need to write the comparator in a way
        // so that the smallest value becomes the greatest value.
        return a.c > b.c;
    }
};

struct Edge
{
    int child, cost;
};

vector<Edge> normalAdj[N];
vector<Edge> reverseAdj[N];
vector<int> startDist;
vector<int> endDist;

// To find the shortest path from node 'node'.
vector<int> dijkstra(int node, vector<Edge> adj[])
{
    vector<int> dist(N, INF);
    vector<bool> vis(N, false);
    priority_queue<Node, vector<Node>, CompareNode> pq;
    // pushing start node as 0 distance node.
    pq.push(Node{node, 0});
    dist[node] = 0;

    while (!pq.empty())
    {
        // taking the current minimum distance node.
        Node parent = pq.top();
        pq.pop();

        if (vis[parent.at])
            continue;
        // if a node is poped then it will not be evaluated/visited again.
        // so marking as visited.
        vis[parent.at] = true;

        // traversing the adj/child nodes of the parent node.
        // to update(if possible) the distances of the child nodes.
        for (Edge e : adj[parent.at])
        {
            if (dist[e.child] == -1 || dist[e.child] > dist[parent.at] + e.cost)
            {
                dist[e.child] = dist[parent.at] + e.cost;
                pq.push(Node{e.child, dist[e.child]});
            }
        }
    }
    return dist;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    // taking edges in the adj array
    for (int i = 0; i < m; i++)
    {
        int x, y, cost;
        cin >> x >> y >> cost;
        //Normal dicrection
        normalAdj[x].push_back(Edge{y, cost});
        //Reverse direction
        reverseAdj[y].push_back(Edge{x, cost});
    }

    // Finding distance from node 1.
    startDist = dijkstra(1, normalAdj);
    // Finding distance from node n.
    endDist = dijkstra(n, reverseAdj);


    int minCost = INT64_MAX;
    for (int city = 1; city <= n; city++) 
    {
        for (Edge e : normalAdj[city]) {
            // if city or the adj cities are not reachable from
            // nodes 1 or node n then we do not count the distance.
            if (startDist[city] == INF || endDist[e.child] == INF)
                continue;
            // after using coupon finding minimum distance.
            minCost = min(minCost, startDist[city] + e.cost / 2 + endDist[e.child]);

        }
    }

    cout << minCost << endl;
}

int32_t main()
{
    Faster;
    solve();

    return 0;
}
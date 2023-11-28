#include <bits/stdc++.h>

using namespace std;
// #define int long long
#define endl "\n"
#define Faster                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define mem(a, b) memset(a, b, sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()

const int N = 1e5+9, INF = 1e9;

struct Node {
    int at, cost;
    Node(int _at, int _cost) {
        at = _at;
        cost = _cost;
    }
};

struct CompareNode {
    bool operator()(const Node& a, const Node& b) const {
        // Priority queue returns the smallest value.
        // So we need to write the comparator in a way
        // so that the smallest value becomes the greatest value.
        return a.cost > b.cost;
    }
};

struct Edge {
    int v, w;
    Edge(int _v, int _w) {
        v = _v;
        w = _w;
    }
};

vector < Edge > adj[N];
priority_queue < Node, vector<Node>, CompareNode > pq;
vector < int > dist;
vector < bool > vis;
vector < int > parents;
vector < int > pathDist;

void travers(int node)
{
    // Difining the dist array 
    // and setting the dist of start node as '0'.
    dist.resize(N, INF);
    dist[node] = 0;
    pq.push(Node(node, 0));
    vis.resize(N, false);
    parents.resize(N, -1);
    pathDist.resize(N);

    while (!pq.empty())
    {
        // Picking the current lowest dist's node in tp.
        Node tp = pq.top(); pq.pop();
        vis[tp.at] = true;

        for (Edge e : adj[tp.at])
        {
            if (vis[e.v])
                continue;
            // Checking the child nodes dist that
            // is it neccessary to update the current dist that have the child node.
            if (dist[e.v] > dist[tp.at] + e.w)
            {
                // updating the dist of child node
                // and setting tp.at node as parent of the child node.
                dist[e.v] = dist[tp.at] + e.w;
                pq.push(Node(e.v, dist[e.v]));
                parents[e.v] = tp.at;
                pathDist[e.v] = e.w;
            }
        }
    }   
}

void solve()
{
    int n, m;
    cin >> n >> m;

    // taking edges in the adj array
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back(Edge(y, w));
    }

    // starting to traverse form start node 1
    travers(1);

    int sum = 0, mx = -1;
    for (int cur = n; cur != -1; cur = parents[cur])
    {
        sum += pathDist[cur];
        mx = max(pathDist[cur], mx);
    }

    cout << mx / 2 + (sum - mx) << endl;
}

int32_t main()
{
    Faster;
    solve();
    
    return 0;
}
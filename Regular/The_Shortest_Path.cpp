#include<bits/stdc++.h>

using namespace std;
#define int long long
#define endl "\n" 
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()

const int N = 1e4+9;

struct Edge {
    int v, w;
    Edge(int _v, int _w) {
        v = _v;
        w = _w;
    }
};

struct Node
{
    int u, w;
    Node(int _u, int _w) {
        u = _u;
        w = _w;
    }
};


struct CompareNode {
    bool operator()(const Node& a, const Node& b) const {
        // Priority queue returns the smallest value.
        // So we need to write the comparator in a way
        // so that the smallest value becomes the greatest value.
        return a.w > b.w;
    }
};

map < string, int > cites;
vector < Edge > adj[N];
vector < int > dist;
vector < bool > vis;
vector < int > directed(N);


int travers_path(string& sCity, string& eCity) {

    priority_queue <Node, vector<Node>, CompareNode> q;
    q.push(Node(cites[sCity], 0));
    dist[cites[sCity]] = 0;

    while (!q.empty()) {
        Node node = q.top(); q.pop();
        vis[node.u] = true;
        // if (node.u == cites[eCity]) {
        //     return dist[cites[eCity]];
        // }

        for (Edge e : adj[node.u]) {
            if (vis[e.v])
                continue;
            if (dist[e.v] == -1 || dist[e.v] > dist[node.u] + e.w) {
                dist[e.v] = dist[node.u] + e.w;
                q.push(Node(e.v, dist[e.v]));
            }
        }
    }
    dist.clear();
    vis.clear();
    return dist[cites[eCity]];
}

void solve() {
    int n; cin >> n;
    for (int c = 1; c <= n; c++) {
        string city; cin >> city;
        cites[city] = c;
        int m; cin >> m;
        for (int i = 0; i < m; i++) {
            int v, w; cin >> v >> w;
            if (i < directed[c])
                continue;
            directed[v]++;
            adj[c].push_back(Edge(v, w));
        }
    }
    int find_path; cin >> find_path;
    for (int i = 0; i < find_path; i++) {
        vis.resize(n+1);
        dist.resize(n+1, -1);
        string sCity, eCity; cin >> sCity >> eCity;
        int minCost = travers_path(sCity, eCity);
        cout << minCost << endl;
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << i << " -> ";
    //     for (int j = 0; j < adj[i].size(); j++) {
    //         cout << adj[i][j].v << " ";
    //     }
    //     cout << endl;
    // }
}

int32_t main() {
    Faster;
    int t; cin >> t;
    while(t--)solve();   
    return 0;
}
#include<bits/stdc++.h>

using namespace std;
//#define int long long
#define endl "\n" 
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()

const int N = 1e5+9, INF = -1;

struct Edge {
    int v, w;
    Edge(int _v, int _w) {
        v = _v;
        w = _w;
    }
};

struct Node {
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

vector < Edge > adj[N];
vector < int > dist(N, INF);
vector < int > parent(N, -1);
vector < bool > vis(N);

void travers() {
    priority_queue < Node, vector <Node>, CompareNode > q;
    q.push(Node(1, 0));
    dist[1] = 0;

    while (!q.empty()) {
        Node a = q.top(); q.pop();
        vis[a.u] = true;

        for (Edge e : adj[a.u]) {
            if (vis[e.v])
                continue;
            if (dist[e.v] == -1 || dist[e.v] > dist[a.u] + e.w) {
                dist[e.v] = dist[a.u] + e.w;
                q.push(Node(e.v, dist[e.v]));
                parent[e.v] = a.u;
            }
        }
    }
}

void printAns(int n) {
    int a = parent[n];
    vector < int > ans;
    ans.push_back(n);
    while (a != -1) {
        ans.push_back(a);
        a = parent[a];
    }
    reverse(all(ans));

    for (auto e : ans) {
        cout << e << " ";
    }
    cout << endl;
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back(Edge(y, w));
        adj[y].push_back(Edge(x, w));
    }

    travers();
    if (dist[n] != -1) {
        printAns(n);
    } else {
        cout << -1 << endl;
    }
}

int32_t main() {
    Faster;
    solve();   
    return 0;
}
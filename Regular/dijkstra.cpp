#include<bits/stdc++.h>

using namespace std;
//#define int long long
#define endl "\n" 
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()

const int N = 1e2;
const int INF = 1e9;

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
vector < int > dist(N, INF);

void dijkstra(int u) {
    dist[u] = 0;
    pq.push(Node(u, 0));

    while (!pq.empty()) {
        Node tp = pq.top(); pq.pop();

        if (tp.cost != dist[tp.at])
            continue;
        
        for (Edge e : adj[tp.at]) {
            if (dist[e.v] > tp.cost + e.w) {
                dist[e.v] = tp.cost + e.w;
                pq.push(Node(e.v, dist[e.v]));
            }
        }
    }
}

int minimum_time(int n) {
    int mn = 0;
    for (int i = 1; i <= n; i++) {
        mn = max(mn, dist[i]);
    }

    return mn;
}

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    for (int i = 0; i < (int)times.size(); i++) {
        adj[times[i][0]].push_back(Edge(times[i][1], times[i][2]));
    }
    dijkstra(k);
    int ans = minimum_time(n);
    if (ans == INF)
        ans = -1;
    return ans;
}

void solve() {
    // vector < vector < int > > times = {{2,1,1}, {2,3,1}, {3,4,1}, {1,2,1}};
    vector < vector < int > > times = {{1,2,1}};
    int n = 4;
    int k = 2;
    cout << networkDelayTime(times, n, k) << endl;
}

int32_t main() {
    Faster;
    solve();   
    return 0;
}
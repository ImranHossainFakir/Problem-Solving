/*
* This is a simple DFS problem. Where we need to determine weather we can go to the leaf nodes.
* time : O(nodes + edges)
*/

#include "bits/stdc++.h"
     
using namespace std;

//#define int long long
#define endl "\n"
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define all(x) (x).begin(), (x).end()
const int N = 1e5+9;
int n, m, cnt;
vector < int > adj[N];
vector < int > cats_nodes;
vector < int > vis;

void dfs(int node, int cats) {
    if (cats > m || vis[node]) return;
    vis[node] = 1;
    if (adj[node].size() == 1 && node != 1) {
        cnt++;
        return;
    }
    if (cats_nodes[node] == 0) cats = 0;
    for (auto child : adj[node]) dfs(child, cats_nodes[child] + cats);
}
void solve() {
    cin >> n >> m;
    cnt = 0;
    cats_nodes.resize(n+1);

    for (int i = 1; i <= n; i++) cin >> cats_nodes[i];
    vis.resize(n+1);

    for (int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, cats_nodes[1]);
    cout << cnt << endl;
}

int32_t main() {
    Faster;
    solve();

    return 0;
}

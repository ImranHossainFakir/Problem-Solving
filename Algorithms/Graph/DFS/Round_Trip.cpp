// Problem link -> https://cses.fi/problemset/task/1669/
// simple dfs problem. 
// We use dfs to search a cycle in every Connected component. 
// if loop/cycle exist then we can say that answer is exist other wise Impossible.

#include "bits/stdc++.h"

using namespace std;

//#define int long long
#define endl "\n"
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define all(x) (x).begin(), (x).end()
const int N = 1e5+9;
int s_node = 0, e_node = 0;
vector < int > adj[N];
vector < bool > vis;
vector < int > parents;
stack < int > ans;

void dfs(int node) {
    vis[node] = true;
    for (auto child : adj[node]) {
        //checking if loops exist then store the start node and end node of the loop
        if (vis[child] && parents[node] != child && !s_node && !e_node) {
            s_node = child;
            e_node = node;
        }
        if (vis[child]) continue;
        parents[child] = node;
        dfs(child);
    }

}
void find_path(int node) {

    ans.push(s_node);
    while (node != s_node) {
        ans.push(node);
        node = parents[node];
    }
    ans.push(s_node);

    cout << ans.size() << endl;
    while (!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
}

void solve() {
    int n, m; cin >> n >> m;
    vis.resize(n+1, false);
    parents.resize(n+1, 0);

    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        dfs(i);
    }

    if (s_node) find_path(e_node);
    else cout << "IMPOSSIBLE" << endl;
}

int32_t main() {
    Faster;
    solve();
    return 0;
}

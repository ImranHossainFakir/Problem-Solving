#include "bits/stdc++.h"
     
using namespace std;
 
//#define int long long
#define endl "\n"
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define all(x) (x).begin(), (x).end()
 
const int N = 1e5+9;
bool flag = true;
 
vector < int > adj[N];
vector < bool > vis(N);
vector < int > team(N);
 
void dfs(int v, int col) {
    if (vis[v]) return;
    vis[v] = true;
    team[v] = col;
 
    for (auto child : adj[v]) {
        int c = col ^ 1;
        dfs(child, c);
        if (team[v] == team[child]) flag = false;
    }
 
    return;
}
 
void print_ans(int n) {
 
    for (int i = 1; i <= n; i++) {
        cout << team[i] + 1 << " ";
    }
 
    return;
}
 
int32_t main() {
    Faster;
 
    int n, m, col; cin >> n >> m;
    col = 0;
 
    for (int i = 1; i <= n; i++) vis[i] = false;
 
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
 
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
 
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        dfs(i, col);
    }
 
    if (flag) print_ans(n);
    else cout << "IMPOSSIBLE" << endl;
 
    return 0;
}

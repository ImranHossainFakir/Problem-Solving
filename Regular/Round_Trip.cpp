#include<bits/stdc++.h>

using namespace std;
//#define int long long
#define endl "\n" 
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()

const int N = 1e5+9;
vector < int > adj[N];
vector < bool > vis(N);
vector < int > parents(N);  
int s_node, e_node;
bool lop_exist = false;

void dfs(int par) {
    // before entering the parent node
    vis[par] = true;
    for (auto child : adj[par]) {
        // before entering the child
        if (vis[child] && parents[par] != child) {
            if (!lop_exist) {
                s_node = child;
                e_node = par;
                lop_exist = true;
            }
        }
        if (vis[child]) 
            continue;
        parents[child] = par;
        dfs(child);
        // after exiting the child node
    }
    //before exiting the parent node
}

void findPath() {
    vector < int > ans;
    ans.push_back(s_node);
    for (int v = e_node; v != s_node; v = parents[v]) 
        ans.push_back(v);
    ans.push_back(s_node);

    reverse(all(ans));
    cout << ans.size() << endl;
    for (auto e : ans) cout << e << " ";
    cout << endl;
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    s_node = e_node = -1;
    for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i);
    if (lop_exist) findPath();
    else cout << "IMPOSSIBLE" << endl;
}

int32_t main() {
    Faster;
    solve();   
    return 0;
}
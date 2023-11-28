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

void dfs(int node) {
    vis[node] = true;

    for (auto child : adj[node]) {
        if (vis[child]) continue;
        dfs(child);
    }
    
}

void solve() {
    int n, m; cin >> n >> m;
    vector < int > roads;
    while (m--) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 1; i < n; i++) {
        if (vis[i]) continue;
        roads.push_back(i);
        dfs(i);
    }

    cout << roads.size() - 1 << endl;
    for (int i = 1; i < (int)roads.size(); i++) {
        cout << roads[i-1] << " " << roads[i] << endl;
    }
}

int32_t main() {
    Faster;
    solve(); 


    
    return 0;
}
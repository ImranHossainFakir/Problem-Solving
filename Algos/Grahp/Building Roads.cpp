#include "bits/stdc++.h"
     
using namespace std;
 
//#define int long long
#define endl "\n"
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define all(x) (x).begin(), (x).end()
 
const int N = 1e5+9;
 
vector < int > adj[N];
vector < bool > vis(N);
 
 
void bfs(int s) {
    if (vis[s]) return;
    vis[s] = true;
 
    for (auto u : adj[s]) {
        bfs(u);
    }
}
 
int32_t main() {
    Faster;
 
    int n, m, cnt; cin >> n >> m;
    cnt = 0;
    vector < int > components;
 
    for (int i = 0; i <= n; i++) vis[i] = false;
 
 
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
 
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
 
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        components.push_back(i);
        bfs(i);
        cnt++;
    }
 
    cout << cnt - 1 << endl;
 
    for (int i = 0; i < cnt - 1; i++) {
        cout << components[i] << " " << components[i+1] << endl;
    }
 
    return 0;
}

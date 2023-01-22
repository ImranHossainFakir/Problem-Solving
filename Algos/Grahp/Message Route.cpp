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
vector < int > p;
 
bool bfs(int n) {
 
    bool flag = false;
    queue < int > q;
    q.push(1);
    vis[1] = true;
    p[1] = -1;
 
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (v == n) flag = true;
 
        for (auto child : adj[v]) {
            if (!vis[child]) {
                vis[child] = true;
                p[child] = v; 
                q.push(child);
            }
        }
    }
    return flag;
}
 
void print_ans(int n) {
    stack < int > s;
    int par = n;
    s.push(n);
    while (p[par] != -1) {
        s.push(p[par]);
        par = p[par];
    }
 
    cout << s.size() << endl;
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
 
    return;
}
 
int32_t main() {
    Faster;
 
    int n, m; cin >> n >> m;
 
    p.resize(n+1);
 
    for (int i = 1; i <= n; i++) vis[i] = false;
 
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
 
    if (bfs(n)) print_ans(n);
    else cout << "IMPOSSIBLE" << endl;
 
    return 0;
}

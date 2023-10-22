
#include "bits/stdc++.h"
     
using namespace std;

#define int long long
#define endl "\n"
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define all(x) (x).begin(), (x).end()

const int N = 3e4+9;
int mx, mx_ind;
vector < pair < int, int > > adj[N];
vector < bool > vis(N);

void dfs(int node, int w) {
    //after entering the node
    vis[node] = true;
    for (auto child : adj[node]) {
        if (vis[child.first]) continue;
        int new_w = child.second + w;
        if (new_w > mx) {
            mx = new_w;
            mx_ind = child.first;
        }
        //before entering the child node
        dfs(child.first, new_w);
        //after exiting the child node
    }
    //before exiting the node
}

void solve() {
   int t; cin >> t;
   for (int cs = 1; cs <= t; cs++) {
    cout << "Case " << cs << ": ";
        int n; cin >> n;
        while (--n) {

            int x, y, w; cin >> x >> y >> w;
            adj[x].push_back({y, w});
            adj[y].push_back({x, w});
        }
        for (int i = 0; i < N; i++) vis[i] = false;
        //assuming node 0 is the mx_ind and initial value mx is 0
        mx = 0;
        mx_ind = 0;
        //finding the farthest node from node 0
        dfs(0, 0);
        for (int i = 0; i < N; i++) vis[i] = false;
        //assuming the farthest node from node 0 is mx_ind. now finding the farthest node from mx_ind.
        dfs(mx_ind, 0);
        for (auto &v : adj) v.clear();
        cout << mx << endl;
   }
}


int32_t main() {
    Faster;
    solve();
    return 0;
}

/*
* Problem link -> https://www.codechef.com/problems/SNSOCIAL
* This is a simple Multiple soucrce BFS problem. We need to determine how much time it will take to cover the entire graph if we start traversing from multiple sources or nodes.
* time : O(row * col)
*/

#include "bits/stdc++.h"
     
using namespace std;

//#define int long long
#define endl "\n"
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define all(x) (x).begin(), (x).end()


const int N = 501;
int n, m, mx, mn;
int vis[N][N];
int dis[N][N];
int x[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int y[] = {0, 0, -1, 1, -1, 1, -1, 1};
struct axis {
    int x, y;
};
bool is_not_ok(int a, int b) {
    return a < 0 || a >= n || b < 0 || b >= m;
}
void bfs(queue < axis > &qu) {
    //cout << "in bfs" << endl;
    while(!qu.empty()) {
        axis front = qu.front();
        //cout << front.x << " " << front.y << endl;
        qu.pop();
        for (int i = 0; i < 8; i++) {
            int a = front.x+x[i], b = front.y+y[i];
            if (is_not_ok(a, b) || vis[a][b]) continue;
            dis[a][b] = dis[front.x][front.y] + 1;
            vis[a][b] = 1;
            qu.push({a, b});
            mn = max(mn, dis[a][b]);
        }
    }
}
void solve() {
    int t; cin >> t;
    while (t--) {
        vector < vector < int > > v;
        mx = INT_MIN, mn = 0; cin >> n >> m;
        queue < axis > qu;
        for (int i = 0; i < n; i++) {
            vector < int > tem;
            for (int j = 0; j < m; j++) {
                int val; cin >> val;
                mx = max(mx, val);
                tem.push_back(val);
                vis[i][j] = 0;
                dis[i][j] = 0;
            }
            v.push_back(tem);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                axis tem; tem.x = i, tem.y = j;
                if (mx == v[i][j]) qu.push(tem), vis[i][j] = 1;
            }
        }
        bfs(qu);
        cout << mn << endl;
    }
}
int32_t main() {
    Faster;
    
    solve();
    return 0;
}


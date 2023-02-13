/*
* Problem link -> https://cses.fi/problemset/task/1192/
* This is a graph problem where we have to find out how many connected components have.
* time : O (row * col)
*/

#include "bits/stdc++.h"
     
using namespace std;

//#define int long long
#define endl "\n"
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define all(x) (x).begin(), (x).end()

const int N = 1e6+9;
int n, m;
int x[] = {-1, 1, 0, 0};
int y[] = {0, 0, -1, 1};
vector < string > input;
vector < int > graph[N];
vector < int > vis;
bool is_ok(int x, int y) {
    return (-1 < x && x < n) && (-1 < y && y < m) && input[x][y] == '.';
}
void make_graph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (input[i][j] == '#') continue;
            for (int k = 0; k < 4; k++) {
                int a = i+x[k], b = j+y[k];
                if (is_ok(a, b)) graph[i*m+j].push_back(a*m+b);
            }
        }
    }
}
void dfs(int node) {
    if (vis[node]) return;
    vis[node] = 1;

    for (auto child : graph[node]) {
        dfs(child);
    }
}
void solve() {
    int cnt = 0; cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string tem; cin >> tem;
        input.push_back(tem);
    }
    vis.resize(n*m);
    make_graph();
    for (int i = 0; i < n*m; i++) {
        if (vis[i] || input[i/m][i%m] == '#') continue;
        dfs(i);
        cnt++;
    }
    cout << cnt << endl;
}   

int32_t main() {
    Faster;
    solve();
    return 0;
}

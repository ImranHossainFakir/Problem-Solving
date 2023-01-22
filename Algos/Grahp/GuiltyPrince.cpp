#include "bits/stdc++.h"
     
using namespace std;

//#define int long long
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define pop pop_back() // remove last value
#define bk back() // return the last value
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define loop(b, e) for (int i = b; i < e; i++)
#define lc (n * 2)
#define rc ((n * 2) + 1)
#define mid ((e+b) / 2)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()

const int N = 1e5+9;

bool vis[N];
string strings[N];
int cnt = 0;

void dfs(int x, int y, int n, int m) {
    int node = (n * x) + y + 1;
    if (vis[node]) return;
    
    vis[node] = true;

    if (x+1 < m && strings[x+1][y] == '.') {
        dfs(x+1, y, n, m);
    }
    if (x-1 > -1 && strings[x-1][y] == '.') {
        dfs(x-1, y, n, m);
    }
    if (y+1 < n && strings[x][y+1] == '.') {
        dfs(x, y+1, n, m);
    }
    if (y-1 > -1 && strings[x][y-1] == '.') {
        dfs(x, y-1, n, m);
    }
}

void solve() {

    int n, m; cin >> n >> m;
    // n = col
    // m = row
    int x, y;
    cnt = 0;

    for (int i = 0; i < N; i++) vis[i] = false;

    for (int i = 0; i < m; i++) cin >> strings[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (strings[i][j] == '#') continue;
            cnt++;
            dfs(i, j, n, m);
        }
    }
    dfs(x, y, n, m);

    cout << cnt << endl;
}

int32_t main() {
    IOS;

    int t; cin >> t;

    for (int cs = 1; cs <= t; cs++) {
        cout << "Case " << cs << ": ";
        solve();
    }

    return 0;
}

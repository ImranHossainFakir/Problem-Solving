#include <bits/stdc++.h>

using namespace std;
// #define int long long
#define endl "\n"
#define Faster                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define mem(a, b) memset(a, b, sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 9;
int timeCnt;


void dfs(int node, vector < int > adj[], vector< int >& vis) {
    // after entering the node
    
    vis[node] = 1;
    for (auto child : adj[node])
    {
        if (vis[child])
            continue;
        // before entering the child node
        dfs(child, adj, vis);
        // after exiting the child node
    }
    // before exiting the node
}

void count_finis_time(int node, vector < int > adj[], vector< int >& vis, vector < int >& f, vector < int >& s) {
    // after entering 
    s[node] = timeCnt++;
    vis[node] = 1;
    for (auto child : adj[node])
    {
        if (vis[child])
            continue;
        // before entering the child node
        count_finis_time(child, adj, vis, f, s);
        // after exiting the child node
    }
    f[node] = timeCnt++;
    // before exiting the node
}



void solve()
{
    int n, m;
    cin >> n >> m;
    vector< int > adj[n+1];
    vector< int > vis(n+1, 0);
    vector < int > f(n+1);
    vector < int > s(n+1);
 
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }

    // counting finish times;
    timeCnt = 1;
    for (int i = 1; i <= n; i++) {
        if (!vis[i])
            count_finis_time(i, adj, vis, f, s);
    }

    vis.clear();
    vis.resize(n+1);

    vector < pair < int, int > > finsh;

    // for Top sort assigning the finishing times
    // to the vecotor of pairs.
    for (int i = 1; i <= n; i++) {
        finsh.push_back({f[i], i});
    }

    sort(all(finsh), greater< pair < int, int > >());

    // just counting knock downs like
    // finding the connected components
    int cnt = 0;
    for (auto [t, u] : finsh) 
    {
        if (!vis[u])
        {
            dfs(u, adj, vis);
            cnt++;
        }
    }
    cout << cnt << endl;

}

int32_t main()
{
    Faster;
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
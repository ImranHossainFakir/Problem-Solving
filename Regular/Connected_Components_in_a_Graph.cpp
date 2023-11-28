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

int const N = 1e3+2;
int n, e;

vector<int> adj[N];
vector<bool> vis(N, false);
map < string , int > mp;

void dfs(int node)
{
    vis[node] = true;
    for (auto child : adj[node])
    {
        if (vis[child]) continue;
        dfs(child);
    }
}

void make_adj() {
    for (int i = 0; i < n; i++) {
        string tem; cin >> tem;
        mp[tem] = i+1;
    }
    for (int i = 0; i < e; i++)
    {
        string x, y; cin >> x >> y; 
        adj[mp[x]].push_back(mp[y]);
        adj[mp[y]].push_back(mp[x]);
    }
}

int count_comp() {
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        cnt++;
        dfs(i);
    }
    return cnt;
}

void solve()
{
    cin >> n >> e;

    make_adj();

    cout << count_comp() << endl;
}

int32_t main()
{
    Faster;
    solve();
    return 0;
}
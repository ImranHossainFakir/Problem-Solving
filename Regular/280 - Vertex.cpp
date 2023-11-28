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

const int N = 101;
vector<int> adj[N];
vector<int> vis;

int sVartex;

void dfs(int sV)
{
    for (auto v : adj[sV])
    {
        if (vis[v] == sVartex)
            continue;
        vis[v] = sVartex;
        dfs(v);
    }
}

void solve()
{
    int n;
    while (cin >> n, n)
    {
        vis.resize(n + 1);
        int a;
        while (cin >> a, a)
        {
            int tem;
            while (cin >> tem, tem)
            {
                adj[a].push_back(tem);
            }
        }
        int b;
        cin >> b;

        while (b--)
        {
            cin >> sVartex;

            dfs(sVartex);

            vector<int> ans;

            for (int i = 1; i <= n; i++)
                if (vis[i] != sVartex)
                    ans.push_back(i);

            cout << (int)ans.size() << " ";

            for (auto e : ans)
                cout << e << " ";
                
            cout << endl;
        }
        for (int i = 0; i < N; i++)
            adj[i].clear();
        vis.clear();
    }
}

int32_t main()
{
    Faster;
    solve();
    return 0;
}
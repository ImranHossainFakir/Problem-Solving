/*
We used BFS to travers all reachable vartexes from starting vartex.

Problem link: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=216

Time complexity: O(t (n + m)) where t, n and m are test cases, vertexes and edges respectively.
*/

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

vector < vector < int > > adj;
vector<int> vis(101);

int sVartex, n;

void bfs(int sV)
{
    for (int i = 1; i <= n; i++)
        vis[i] = 0;
    
    queue < int > q;
    q.push(sV);

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (auto child : adj[u]) {
            if (vis[child]) 
                continue;
            vis[child] = 1;
            q.push(child);
        }
    }
}

void solve()
{
    while (1)
    {
        cin >> n;
        if (!n)
            break;
        adj.resize(n + 1);
        int a;
        while (1)
        {
            cin >> a;
            if (!a)
                break;
            int tem;
            while (1)
            {
                cin >> tem;
                if (!tem)
                    break;
                adj[a].push_back(tem);
            }
        }
        int b;
        cin >> b;

        while (b--)
        {
            cin >> sVartex;

            bfs(sVartex);
            int cnt = 0;

            for (int i = 1; i <= n; i++) {
                if (!vis[i]) cnt++;
            }

            cout << cnt;

            for (int i = 1; i <= n; i++) {
                if (!vis[i]) cout << " " << i;
            }
                
            cout << endl;
        }
        adj.clear();
    }
}

int32_t main()
{
    Faster;
    solve();
    return 0;
}



/*

Problem link:https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=4474
Time Complexity:

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

const int N = 1e5 + 9;

struct Edge
{
    int v, level;
    Edge(int _v, int _level)
    {
        v = _v;
        level = _level;
    }
};

vector<Edge> adj[N];
vector<int> not_necceassary(N, 1);

// Here we are finding the depths
// for all 'n' nodes from sNode.
vector<int> bfs(int sNode)
{
    vector<int> depths(N);
    vector<bool> vis(N, false);
    queue<int> q;
    q.push(sNode);
    vis[sNode] = true;
    int d = 0;

    while (!q.empty())
    {
        d++;
        int sz = q.size();
        while (sz--)
        {

            int frnt = q.front();
            q.pop();
            for (Edge e : adj[frnt])
            {
                if (vis[e.v])
                    continue;
                depths[e.v] = d;
                q.push(e.v);
                vis[e.v] = true;
            }
        }
    }
    return depths;
}

int find_min_level(queue<int> q)
{
    int sz = q.size();
    int mn = INT_MAX;
    while (!q.empty())
    {
        // 'frnt' = current door
        int frnt = q.front();
        q.pop();

        // adj[frnt] = passages from 'frnt' door
        // finding minimum level
        for (int i = 0; i < (int)adj[frnt].size(); i++)
            mn = min(mn, adj[frnt][i].level);
    }
    return mn;
}

vector<int> find_ideal_path()
{
    vector<bool> vis(N, false);
    queue<int> q;
    q.push(1);
    vis[1] = true;
    vector<int> ans;
    ans.push_back(1);

    while (!q.empty())
    {
        int sz = q.size();
        // 'mn' will hold the minimum level of the edges
        // of the next passages.
        int mn = find_min_level(q);

        while (sz--)
        {
            // 'frnt' = current door
            int frnt = q.front();
            q.pop();

            // adj[frnt] = passages from 'frnt' door
            // finding minimum level
            for (int i = 0; i < (int)adj[frnt].size(); i++)
            {
                if (!not_necceassary[adj[frnt][i].v] || vis[adj[frnt][i].v])
                {

                }
                else if (adj[frnt][i].level == mn)
                {
                    q.push(adj[frnt][i].v);
                }
            }
            ans.push_back(mn);
        }
    }
    return ans;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    // Taking the paths and levels of passeges
    for (int i = 0; i < m; i++)
    {
        int x, y, lv;
        cin >> x >> y >> lv;
        adj[x].push_back(Edge(y, lv));
        adj[y].push_back(Edge(x, lv));
    }

    // finding depths from nodes '1' and 'n'
    vector<int> from_start_depths = bfs(1);
    vector<int> from_end_depths = bfs(n);

    // checking node 'u' (1<u<n) if the depth
    // (1 to u) + (n to u) == (1 to n)
    // if not then we will remove this node.
    // We don't need that node.
    for (int u = 2; u < n; u++)
        if (from_start_depths[u] + from_end_depths[u] != from_start_depths[n])
            not_necceassary[u] = 0; // marking as remove

    vector<int> ans = find_ideal_path();

    cout << (int)ans.size() << endl;

    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
            cout << ans[i];
        else
            cout << ans[i] << " ";
    }
}
int32_t main()
{
    Faster;

    solve();
    return 0;
}
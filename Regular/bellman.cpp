#include <bits/stdc++.h>

using namespace std;
// #define int long long
#define endl "\n"
#define Faster                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define mem(u, v) memset(u, v, sizeof(u))
#define len(u) sizeof(u) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()

struct Edge
{
    int u, v, cost;
    Edge(int _u, int _v, int _cost)
    {
        u = _u;
        v = _v;
        cost = _cost;
    }
};
const int INF = 1e9;
vector<Edge> E;
vector<int> dist;
vector<int> path;

int n, v;

void find_path() 
{

    int dest = 4;
    if (dist[dest] == INF)
        cout << "There have no path from " << 1 << " to " << dest << endl;
    else 
    {
        vector < int > ans;
        for (int cur = dest; cur != -1; cur = path[cur])
            ans.push_back(cur);
        reverse(all(ans));
        cout << "Path from " << 1 << " to " << dest << ": " << endl;
        for (auto p : ans)
            cout << p << " "; i
    }
}

void bellman_ford(int s)
{
    dist[s] = 0;

    // If there have no negative cycle 
    // then we can write like this.
    // Other wise we have to iterate from 1 -> n.
    // If we don't specify the limit of the loop inside the for loop
    // then it will iterate infinitly.
    for (; ;)
    {
        bool any = false;

        for (Edge e : E)
            if (dist[e.u] < INF)
                if (dist[e.v] > dist[e.u] + e.cost)
                {
                    dist[e.v] = dist[e.u] + e.cost;
                    path[e.v] = e.u;
                    any = true;
                }

        if (!any)
            break;
    }
    find_path();
}


void solve()
{
    int m;
    cin >> n >> m;
    dist.resize(n + 1, INF);
    path.resize(n + 1, -1);

    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        E.push_back(Edge(x, y, w));
    }

    bellman_ford(1);
}

int32_t main()
{
    Faster;
    solve();
    return 0;
}
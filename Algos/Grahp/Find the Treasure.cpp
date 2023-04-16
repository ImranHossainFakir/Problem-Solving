/*
* Problem link -> https://www.spoj.com/problems/DIGOKEYS/
* finding shortest path with bfs in a sorted connected graph.
*/

#include "bits/stdc++.h"

using namespace std;

// #define int long long
#define endl "\n"
#define Faster                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define mem(a, b) memset(a, b, sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 2;
int n;

bool bfs(vector<int> &parent, vector<bool> &vis, vector<set<int>> &adj)
{
    queue<int> q;
    q.push(1);
    vis[1] = true;
    parent[1] = -1;

    while (!q.empty())
    {
        int frnt = q.front();
        q.pop();
        if (frnt == n)
            return true;
        for (auto e : adj[frnt])
        {
            if (vis[e])
                continue;
            vis[e] = true;
            q.push(e);
            parent[e] = frnt;
        }
    }

    return false;
}

void make_graph_from_input(vector<set<int>>& adj)
{
    set<int> tem;
    tem.insert(0);
    adj.push_back(tem);
    for (int i = 1; i < n; i++)
    {
        int m;
        cin >> m;
        set<int> tem1;
        while (m--)
        {
            int x;
            cin >> x;
            tem1.insert(x);
        }
        adj.push_back(tem1);
    }
}

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<set<int>> adj;
        vector<int> parent(n + 3);
        vector<bool> vis(n + 3);
        make_graph_from_input(adj);
        bool reached = bfs(parent, vis, adj);

        //cout << endl;
        if (reached)
        {
            stack<int> st_ans;
            while (parent[n] != -1)
            {
                st_ans.push(parent[n]);
                n = parent[n];
            }

            cout << st_ans.size() << endl;
            while (!st_ans.empty())
            {
                cout << st_ans.top() << " ";
                st_ans.pop();
            }
        }
        else
            cout << -1;

        cout << endl;
    }
}

int32_t main()
{
    Faster;
    solve();

    return 0;
}

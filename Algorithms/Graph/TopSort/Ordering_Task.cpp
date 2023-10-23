/*
  This is an O(n^2) Solution.
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
#define what_is(x) cerr << #x << " = " << x << endl;
#define all(x) (x).begin(), (x).end()

int n, m;


vector<int> bfs(vector<int> adj[], vector<int> &indegree)
{
    vector<int> solution;

    queue<int> q;
  
    // Pushing all independent tasks in the queue
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    
    while (!q.empty())
    {
        // Taking current independent task.
        int u = q.front();
        q.pop();
        solution.push_back(u);
        // Reducing the indegrees of all tasks corresponding to the current independent task.
        for (auto v : adj[u])
        {
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
    }

    return solution;
}

void solve()
{
    while (cin >> n >> m, n != 0 || m != 0)
    {
        vector<int> adj[n + 1];
        vector<int> indegree(n + 1);
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            indegree[y]++;
        }

        vector<int> solution = bfs(adj, indegree);
        for (auto e : solution)
            cout << e << " ";
        cout << endl;
    }
}

int32_t main()
{
    Faster;
    solve();
    return 0;
}

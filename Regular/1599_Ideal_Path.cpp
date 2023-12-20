

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
const int INF = INT_MAX;
int n, m, d;

vector<pair<int, int>> adj[N];
vector<int> from_start_depths;
vector<int> from_end_depths(N, -1);
vector<int> childOrNot(N);

// Here we are finding the depths
// for all 'n' nodes from sNode.
vector<int> bfs(int sNode)
{
    vector<int> depths(N, -1);
    queue<int> q;
    q.push(sNode);
    depths[sNode] = 0;
    d = 0;

    while (!q.empty())
    {
        d++;
        int sz = q.size();
        while (sz--)
        {
            int frnt = q.front(); q.pop();
            for (auto [child, cost] : adj[frnt])
            {
                // Checking depth of child is updated or not
                if (depths[child] != -1)
                    continue;

                depths[child] = d;
                q.push(child);
            }
        }
    }
    return depths;
}

int findCurLeayerMinValue(queue<int> q, int d)
{
    vector<int> ans(N, INF);
    vector<bool> vis(N, false);
    vector<int> depths(N, N);
    int mn = INF;

    while (!q.empty())
    {
        int parent = q.front(); q.pop();

        for (auto [child, level] : adj[parent])
        {

            // Checking nodes with a depth greater than the target depth required to reach node 'n'.
            // 2nd condition checks ensures that reachable from n to child node.
            if (d > from_start_depths[child] || from_start_depths[child] + from_end_depths[child] != from_start_depths[n])
                continue;
            // storing current leayer's minimum level.
            mn = min(mn, level);
        }
    }
    return mn;
}

// We are finding the minimum level for eache parent or each tree level.
vector<int> find_ideal_path()
{
    vector<int> ans;
    vector<bool> vis(N, false);
    vector<bool> vis_as_parent(N, false);
    queue<int> q;

    q.push(1);
    vis[1] = true;
    int d = 0;

    while (!q.empty())
    {
        int sz = q.size();
        d++;
        int mn = findCurLeayerMinValue(q, d);
        ans.push_back(mn);
        while (sz--)
        {
            int parent = q.front();
            q.pop();
            // current depth or leayer.
            // This vector tracks nodes that have already been visited as parent
            // and ensures they will not be visited again in the future.
            vis_as_parent[parent] = true;

            for (auto [child, level] : adj[parent])
            {
                // if true then the child node is already visited as parent.
                if (vis_as_parent[child])
                    continue;
                // Checking nodes with a depth greater than the target depth required to reach node 'n'.
                if (d > from_start_depths[child] || from_start_depths[child] + from_end_depths[child] != from_start_depths[n])
                    continue;
                // once a child is visited then
                // we will not push that child node 2nd time.
                if (level == mn && !vis[child])
                {
                    q.push(child);
                    vis[child] = true;
                }
            }
        }
    }

    return ans;
}

void solve()
{
    cin >> n >> m;

    // Taking the paths and levels of passeges
    for (int i = 0; i < m; i++)
    {
        int x, y, lv;
        cin >> x >> y >> lv;

        // if (x == y) continue;

        adj[x].push_back({y, lv});
        adj[y].push_back({x, lv});
    }

    from_start_depths = bfs(1); // depths from 1 to all nodes
    from_end_depths = bfs(n); // depths from n to all nodes

    // finding the minimum level path
    vector<int> ans = find_ideal_path();

    int d = from_start_depths[n];
    cout << d << endl;

    for (int i = 0; i < d; i++)
    {
        if (i == d - 1)
            cout << ans[i] << endl;
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

// #include<bits/stdc++.h>
// using namespace std;
// #define MAXN 131072

// vector< pair<int, int> > g[MAXN];
// int dist[MAXN][3], visited[MAXN], preColor[MAXN], ret[MAXN];

// void bfs(int n) {
//     // filling the vectors g and arrays with there initial values.
//     for (int i = 1; i <= n; i++) {
//         dist[i][0] = dist[i][1] = dist[i][2] = 0;
//         visited[i] = 0, ret[i] = 0x3f3f3f3f, preColor[i] = 0x3f3f3f3f;
//     }

//     queue<int> Q;
//     Q.push(n), dist[n][0] = 1;
//     while (!Q.empty()) {
//         int parent = Q.front();
//         Q.pop();

//         // traversing all child nodes of parent node.
//         for (auto [child, cost] : g[parent]) {

//             if (dist[child][0] == 0) {

//                 dist[child][0] = dist[parent][0] + 1; // updating the child node's dist.
//                 dist[child][1] = parent; // updating child node's parent node.
//                 dist[child][2] = cost; // updating the passage level.
//                 Q.push(child);
//             }
//             if (dist[child][0] == dist[parent][0] + 1 && cost < dist[child][2]) {
//                 dist[child][1] = parent;
//                 dist[child][2] = cost; // updating the level with lower cost.
//             }
//         }
//     }

//     Q.push(1), visited[1] = 1;
//     ret[dist[1][0]] = dist[1][2];
//     while (!Q.empty()) {
//         int parent = Q.front();
//         Q.pop();
//         if (parent != 1 && preColor[parent] != ret[dist[parent][0]])
//             continue;
//         for (auto [child, cost] : g[parent]) {

//             if (dist[child][0] == dist[parent][0] - 1) {
//                 preColor[child] = min(preColor[child], cost);
//                 ret[dist[child][0]] = min(ret[dist[child][0]], cost);
//                 if (visited[child] == 0) {
//                     visited[child] = 1;
//                     Q.push(child);
//                 }
//             }
//         }
//     }

//     int depth = dist[1][0] - 1;
//     cout << depth << endl;
//     for (int i = depth; i >= 1; i--)
//     {
//         if (i == 1)
//             cout << ret[i] << endl;
//         else
//             cout << ret[i] << " ";
//     }
// }
// int main() {
//     int n, m, x, y, cost;
//     while (scanf("%d %d", &n, &m) == 2) {
//         for (int i = 1; i <= n; i++)
//             g[i].clear();
//         for (int i = 0; i < m; i++) {
//             cin >> x >> y >> cost;
//             if (x == y)
//                 continue;
//             g[x].push_back(make_pair(y, cost));
//             g[y].push_back(make_pair(x, cost));
//         }
//         bfs(n);
//     }
//     return 0;
// }
/*
 4 6
 1 2 1
 1 3 2
 3 4 3
 2 3 1
 2 4 4
 3 1 1

 4 4
 1 2 1
 1 3 1
 2 4 4
 3 4 3

 20 26
 7 16 1
 16 12 1
 17 9 6
 2 16 1
 14 16 1
 1 11 1
 18 16 1
 1 14 1
 1 15 1
 1 18 1
 5 3 4
 1 10 1
 9 6 2
 15 16 1
 4 16 1
 8 20 2
 19 8 8
 10 16 1
 6 19 3
 12 5 7
 1 4 1
 13 17 6
 1 2 1
 1 7 1
 11 16 1
 3 13 8

 */


// /*

// Problem link:https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=4474
// Time Complexity:

// */

// #include <bits/stdc++.h>

// using namespace std;
// // #define int long long
// #define endl "\n"
// #define Faster                    \
//     ios_base::sync_with_stdio(0); \
//     cin.tie(0);                   \
//     cout.tie(0);
// #define mem(a, b) memset(a, b, sizeof(a))
// #define len(a) sizeof(a) / sizeof(int)
// #define what_is(x) cerr << #x << " is " << x << endl;
// #define all(x) (x).begin(), (x).end()

// const int N = 1e5 + 9;
// const int INF = INT_MAX;
// vector < vector < int > >  adj(N, vector<int>(N, INF));

// // Here we are finding the depths
// // for all 'n' nodes from sNode.
// vector<int> bfs(int sNode)
// {
//     vector<int> depths(N);
//     vector<bool> vis(N, false);
//     queue<int> q;
//     q.push(sNode);
//     vis[sNode] = true;
//     int d = 0;

//     while (!q.empty())
//     {
//         d++;
//         int sz = q.size();
//         while (sz--)
//         {

//             int frnt = q.front();
//             q.pop();
//             for (Edge e : adj[frnt])
//             {
//                 if (vis[e.child])
//                     continue;
//                 depths[e.child] = d;
//                 q.push(e.child);
//                 vis[e.child] = true;
//             }
//         }
//     }
//     return depths;
// }

// // Finding the minimum level of the current parent nodes' child node's
// int find_min_level(queue<int> &q)
// {
//     vector < int > vis(N, false);
//     int mn = INT_MAX;

//     while (!q.empty())
//     {
//         // 'frnt' = current parent node
//         int frnt = q.front();
//         q.pop();
//         vis[frnt] = true;
//         what_is(frnt);
//         // adj[frnt] = passages from 'frnt' node
//         // finding minimum level
//         for (Edge e : adj[frnt])  {
//             if (vis[e.child] || !not_necceassary[e.child])
//                 continue;
//             what_is(e.child);
//             what_is(e.level);
//             vis[e.child] = true;
//             mn = min(mn, e.level);
//         }
//     }
//     return mn;
// }

// // We are finding the minimum level for eache parent or each tree level.
// vector<int> find_ideal_path()
// {
//     vector<bool> vis(N, false);
//     queue<int> q;
//     q.push(1);
//     vis[1] = true;
//     vector<int> ans;
//     ans.push_back(1);

//     // Picking the parent node and
//     // at first finding the minimum level among the all chile nodes' levels.
//     while (!q.empty())
//     {
//         int sz = q.size();
//         queue<int> tem = q;
//         // 'mn' will hold the minimum level 
//         // of the edges of the parent nodes
//         int mn = find_min_level(tem);
//         // what_is(mn);
//         // what_is(tem.size());

//         while (sz--)
//         {
//             // 'frnt' = current door
//             int frnt = q.front();
//             q.pop();
//             vis[frnt] = true;
//             // what_is(frnt);

//             // adj[frnt] = passages from 'frnt' door
//             // finding minimum level
//             for (Edge e : adj[frnt])
//             {
//                 if (!not_necceassary[e.child] || vis[e.child])
//                     continue;

//                 q.push(e.child);
//             }
//             ans.push_back(mn);
//         }
//     }
//     return ans;
// }

// void solve()
// {
//     int n, m;
//     cin >> n >> m;

//     // Taking the paths and levels of passeges
//     for (int i = 0; i < m; i++)
//     {
//         int x, y, lv;
//         cin >> x >> y >> lv;

//         // Skip self-connections and select the lowest level.
//         if (x == y || adj[x][y] <= lv)
//             continue;

//         // adjacent matrix
//         adj[x][y] = lv;
//     }

//     // finding depths from nodes '1' and 'n'
//     vector<int> from_start_depths = bfs(1);
//     vector<int> from_end_depths = bfs(n);

//     // checking node 'parent' (1<parent<n) whether the depth
//     // (1 to parent) + (n to parent) == (1 to n)
//     // if not then we will remove this node.
//     // We don't need that node.
//     for (int parent = 2; parent < n; parent++)
//         if (from_start_depths[parent] + from_end_depths[parent] != from_start_depths[n])
//             not_necceassary[parent] = 0; // marking as removed

//     // finding the minimum level path
//     vector<int> ans = find_ideal_path();

//     cout << (int)ans.size() << endl;

//     for (int i = 0; i < n; i++)
//     {
//         if (i == n - 1)
//             cout << ans[i];
//         else
//             cout << ans[i] << " ";
//     }
// }
// int32_t main()
// {
//     Faster;

//     solve();
//     return 0;
// }
































#include<bits/stdc++.h>
using namespace std;
#define MAXN 131072

vector< pair<int, int> > g[MAXN];
int dist[MAXN][3], visited[MAXN], preColor[MAXN], ret[MAXN];

void bfs(int n) {
    // filling the vectors g and arrays with there initial values.
    for (int i = 1; i <= n; i++) {
        dist[i][0] = dist[i][1] = dist[i][2] = 0;
        visited[i] = 0, ret[i] = 0x3f3f3f3f, preColor[i] = 0x3f3f3f3f;
    }

    queue<int> Q;
    Q.push(n), dist[n][0] = 1;
    while (!Q.empty()) {
        int parent = Q.front();
        Q.pop();

        // traversing all child nodes of parent node.
        for (auto [child, cost] : g[parent]) {

            if (dist[child][0] == 0) {
                
                dist[child][0] = dist[parent][0] + 1; // updating the child node's dist.
                dist[child][1] = parent; // updating child node's parent node.
                dist[child][2] = cost; // updating the passage level.
                Q.push(child);
            }
            if (dist[child][0] == dist[parent][0] + 1 && cost < dist[child][2]) {
                dist[child][1] = parent; 
                dist[child][2] = cost; // updating the level with lower cost.
            }
        }
    }

    Q.push(1), visited[1] = 1;
    ret[dist[1][0]] = dist[1][2];
    while (!Q.empty()) {
        int parent = Q.front();
        Q.pop();
        if (parent != 1 && preColor[parent] != ret[dist[parent][0]])
            continue;
        for (auto [child, cost] : g[parent]) {

            if (dist[child][0] == dist[parent][0] - 1) {
                preColor[child] = min(preColor[child], cost);
                ret[dist[child][0]] = min(ret[dist[child][0]], cost);
                if (visited[child] == 0) {
                    visited[child] = 1;
                    Q.push(child);
                }
            }
        }
    }

    int depth = dist[1][0] - 1;
    cout << depth << endl;
    for (int i = depth; i >= 1; i--) {
        printf("%d%cost", ret[i], i == 1 ? '\n' : ' ');
    }
}
int main() {
    int n, m, x, y, cost;
    while (scanf("%d %d", &n, &m) == 2) {
        for (int i = 1; i <= n; i++)
            g[i].clear();
        for (int i = 0; i < m; i++) {
            cin >> x >> y >> cost;
            g[x].push_back(make_pair(y, cost));
            g[y].push_back(make_pair(x, cost));
        }
        bfs(n);
    }
    return 0;
}
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
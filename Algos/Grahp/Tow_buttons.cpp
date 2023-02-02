/* 
* Problem Link -> https://codeforces.com/problemset/problem/520/B
* We can use BFS to find out the shortesh path of the steps that to get m from n.
* step 1: we connecting possible and unvisited nodes of the parent node.
* step 2: checking thet weather current node is same as target value or node.
* step 3: is target value found then return the value or repeate step 1.
* step 4: just count the edges from m to n.
*
* Time : O(m-n)
*        O(log m) in best case
* 
*/


#include "bits/stdc++.h"
     
using namespace std;

//#define int long long
#define endl "\n"
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define all(x) (x).begin(), (x).end()
const int N = 1e6+9;
int p[N];
vector < bool > vis(N);

int bfs(int n, int m) {
    queue < int > q;
    q.push(n);
    p[n] = -1;
    vis[n] = true;
    int frnt = q.front();

    while (!q.empty()) {
        frnt = q.front();
        q.pop();
      
        // here we connecting all possible paths that are not visited yet
        if (frnt-1 > 0 && !vis[frnt-1]) {
            q.push(frnt-1);
            p[frnt-1] = frnt;
            vis[frnt-1] = true;
        }
        if (frnt <= m && !vis[frnt*2]) {
            q.push(frnt*2);
            p[frnt*2] = frnt; 
            vis[frnt*2] = true;
        } 
             
        if (frnt == m) return frnt;
    }
    return frnt;
}

int solve() {
    int n, m, ans = 0, cur_node; cin >> n >> m;
    cur_node = bfs(n, m);
    
   
    // counting shortest path edges from the expected node
    while (p[cur_node] != -1) {
        s.push(cur_node);
        ans++;
        cur_node = p[cur_node];
    }
    return ans;
}

int32_t main() {
    Faster;

    cout << solve() << endl;

    return 0;
}

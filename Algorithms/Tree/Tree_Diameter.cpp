/*
This is simple a DFS problem. At first we try to find out the the most distant node from node 1.
Then we apply DFS again from the most distant node and finally we will get the diameter of the tree.

Time Complexity : O(n+m) where n is node number and m is edge number.

Problem Link : https://cses.fi/problemset/task/1131/
*/

#include<bits/stdc++.h>

using namespace std;
//#define int long long
#define endl "\n" 
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()

const int N = 2e5+9;
int sNode, mxLen;

vector < int > adj[N];
vector < bool > vis(N);

void dfs(int node, int len) {
    // after entering the node
    vis[node] = true;

    for (auto child : adj[node]) {
        if (vis[child])
            continue;
        // before entering child node
        if (mxLen < len+1) {
            mxLen = len+1;
            sNode = child;
        }
        dfs(child, len+1);
        // after exiting child node
    }
    // before exiting the node
}

void solve() {
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    mxLen = 0;
    sNode = 1;
    dfs(sNode, mxLen);
    mxLen = 0;
    vis.clear();
    vis.resize(n+1);
    dfs(sNode, mxLen);

    cout << mxLen << endl;
    
}

int32_t main() {
    Faster;
    solve();   
    return 0;
}

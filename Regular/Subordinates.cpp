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

vector < int > adj[N];
vector < int > vis(N);
vector < int > subOr;

void dfs(int par) {
    // after entering the par node
    vis[par] = 1;

    for (auto child : adj[par]) {
        if (vis[child])
            continue;
        // before entering the child node
        dfs(child);
        // after exiting the child node
        subOr[par] += subOr[child] + 1;
    }
    // before exiting the par node
}

int cal(int node) {
    if (adj[node].size() == 0)
        return 1;
    else {
        for (auto child : adj[node])
        {
            subOr[node] += cal(child);
        }
    }
    return subOr[node] + 1;
}

void solve() {
    int n; cin >> n; 
    
    for (int i = 0; i < n-1; i++) 
    {
        int x; cin >> x;
        adj[x].push_back(i+2);
    }
    subOr.resize(n+1);

    // dfs(1);
    cal(1);

    for (int i = 1; i <= n; i++) cout << subOr[i] << " ";
    cout << endl;
}

int32_t main() {
    Faster;
    solve();   
    return 0;
}
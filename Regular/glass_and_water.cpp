#include<bits/stdc++.h>

using namespace std;
//#define int long long
#define endl "\n" 
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()
const int N = 1e3;

struct node {
    int state[3];
} sz, initial;

bool vis[N][N];
int req;

bool bfs() {
    queue < node > q;
    q.push(initial);
    vis[initial.state[0]][initial.state[1]] = true;
    int total = initial.state[0] + initial.state[1] + initial.state[2];

    while (!q.empty())
    {
        node cur = q.front();
        q.pop();
        if (cur.state[0] == req || cur.state[1] == req || cur.state[2] = req)
            return true;
        int st1[3], st2[3], a, b;
        // picking first glass

        // picking second glass
        
        // picking third glass
        
    }
    
}

void solve() {
    int a, b, c; cin >> a >> b >> c;
    sz.state = {a, b, c};
    cin >> a >> b >> c;
    initial.state = {a, b, c};
    cin >> req;
    for (int i = 0; i < N; i++)
        mem(vis[i], false);
    bfs();
}

int32_t main() {
    Faster;

    solve();
    return 0;
}
#include<bits/stdc++.h>

using namespace std;
//#define int long long
#define endl "\n" 
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()

pair < int, int > two_digree(vector < int >& nodes) {
    pair < int, int > ans;
    int n = nodes.size(), mx = nodes[n-1], cnt = 0;
    for (auto e : nodes) if (mx == e) cnt++;
    ans.second = mx - 1;
    ans.first = max(1, cnt-1);

    return ans;
}

pair < int, int > three_digree(vector < int >& nodes) {
    pair < int, int > ans;
    int n = nodes.size(), mx_2 = 0, mx = nodes[n-1], cnt = 0;
    for (auto e : nodes) {
        if (mx == e) cnt++;
        else {
            mx_2 = max(mx_2, e);
        }
    }
    if (cnt == 1) {
        ans.first = mx;
        ans.second = mx_2-1;
    } else {
        ans.first = mx_2;
        ans.second = mx-1;
    }

    return ans;
}

void solve() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector < int > nodes(n);
        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            nodes[u-1]++;
            nodes[v-1]++;
        }
        sort(all(nodes));
        set < int > s;
        for (auto e : nodes) s.insert(e);
        pair < int, int > ans;
        if (s.size() == 2) ans = two_digree(nodes);
        else ans = three_digree(nodes);

        cout << ans.first << " " << ans.second << endl;
    }
}

int32_t main() {
    Faster;
    solve();
    return 0;
}
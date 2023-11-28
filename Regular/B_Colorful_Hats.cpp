#include<bits/stdc++.h>

using namespace std;
//#define int long long
#define endl "\n" 
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()

int find_alone_col(vector < int > dif_col, int mn) {
    int cnt = 0;
    for (auto e : dif_col) if (e == mn) cnt++;
    return cnt;
}

void solve() {
    int n, mx = 0, mn = 1e5, cnt; cin >> n;
    vector < int > dif_col(n);

    for (auto& e : dif_col) {
        cin >> e;
        mx = max(mx, e);
        mn = min(mn, e);
    }
    cnt = find_alone_col(dif_col, mn);
    if (mx == mn && (mx == n-1 || mx <= n/2)) cout << "Yes" << endl;
    else if (mx - mn == 1 && cnt < mx && mx <= (n-cnt) / 2 + cnt) cout << "Yes" << endl;
    else cout << "No" << endl;
    
}

int32_t main() {
    Faster;
    
    solve();
    return 0;
}
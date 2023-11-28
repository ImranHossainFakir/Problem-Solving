#include<bits/stdc++.h>

using namespace std;
#define int long long
#define endl "\n" 
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()

void solve() {
    int n, k, x; cin >> n >> k >> x;
    int mn, mx;
    mn = k * (k+1) / 2;
    mx = (n * (n+1) / 2) - ((n-k) * (n-k+1) / 2);
    if (mn <= x && x <= mx) cout << "YES" << endl;
    else cout << "NO" << endl;    
}

int32_t main() {
    Faster;
    int t; cin >> t;
    while(t--) solve();   
    return 0;
}
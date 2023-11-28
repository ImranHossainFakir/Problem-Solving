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
    int n, k; cin >> n >> k;
    int a = k / (n-1);
    int rem = k % (n-1);
    cout << (rem == 0 ? a*n-1 : a*n+rem) << endl;
}

int32_t main() {
    Faster;
    int t; cin >> t;
    while (t--) solve();   
    return 0;
}
#include<bits/stdc++.h>

using namespace std;
//#define int long long
#define endl "\n" 
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()

void solve() {
    int n, op = 0, ind = -1; cin >> n;
    vector < int > arr(n);

    for (auto& e : arr) cin >> e;

    for (int i = 0; i < n-1; i++) {
        if (arr[i] > arr[i+1]) {
            ind = i;
        }
    }

    if (ind == -1) {
        cout << 0 << endl;
        return;
    }

    int ans = *max_element(arr.begin(), arr.begin()+ind+1);
    cout << ans << endl;
    
}

int32_t main() {
    Faster;
    int t; cin >> t;
    while (t--) solve();   
    return 0;
}
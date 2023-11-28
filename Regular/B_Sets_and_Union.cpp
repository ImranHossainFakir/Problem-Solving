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
    int n; cin >> n;
    set < int > allItem;
    vector < set < int > > arr(n);
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        while(k--) {
            int tem; cin >> tem;
            arr[i].insert(tem);
            allItem.insert(tem);
        }
    }
    int ans = 0;
    for (int i = 1; i <= 50; i++) {
        set < int > taken;
        for (int j = 0; j < n; j++) {
            if (arr[j].count(i)) continue;
            for (auto e : arr[j]) taken.insert(e);
        }
        if (taken.size() != allItem.size()) ans = max(ans, (int)taken.size());
    }
    cout << ans << endl;
}

int32_t main() {
    Faster;
    int t; cin >> t;
    while(t--) solve();   
    return 0;
}
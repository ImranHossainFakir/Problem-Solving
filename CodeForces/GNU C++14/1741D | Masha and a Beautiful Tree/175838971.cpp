#include "bits/stdc++.h"
     
using namespace std;
 
//#define int long long
#define endl "\n"
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back // add in last position
#define pop pop_back() // remove last value
#define bk back() // return the last value
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define all(x) (x).begin(), (x).end()
 
vector < int > arr;
int ans;
 
void solve(int l, int r) {
    int mid = (l + r) / 2;
    if (l == r) {
        return;
    }
 
    solve(l, mid);
    solve(mid+1, r);
 
    if (arr[l] > arr[mid+1]) {
        ans++;
        for (int i = l, j = 1; i < mid+1; i++, j++) {
            int swap = arr[i];
            arr[i] = arr[mid+j];
            arr[mid+j] = swap;
        }
    }
}
 
int32_t main() {
    Faster
 
    int t; cin >> t;
 
    while (t--) {
        int n; cin >> n;
 
        arr.resize(n+1);
 
        for (int i = 1; i <= n; i++) cin >> arr[i];
 
        ans = 0;
 
        solve(1, n);
 
        if (is_sorted(arr.begin()+1, arr.end())) cout << ans << endl;
        else cout << -1 << endl;
    }
    return 0;
}
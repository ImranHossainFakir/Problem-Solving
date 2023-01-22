#include "bits/stdc++.h"
     
using namespace std;
 
//#define int long long
#define endl "\n"
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define all(x) (x).begin(), (x).end()
 
const int N = 1e5+9;
const int R = 1e9;
 
int n, c, arr[N];
 
bool ok(int mid) {
    int cnt = 1, p = 1;
    for (int i = 2; i <= n; i++) {
        if (arr[i] - arr[p] >= mid) {
            p = i;
            cnt++;
        }
        if (cnt >= c) return 1;
    }
 
    return 0;
}
 
int solve() {
    int first, last, mid, ans;
    first = 1;
    last = R;
 
    while (first <= last) {
        mid = (first + last) / 2;
        if (ok(mid)) {
            ans = mid;
            first = mid + 1;
        }
        else {
            last = mid - 1;
        }
    }
 
    return ans;
}
 
int32_t main() {
    Faster;
 
    int t; cin >> t;
 
    while (t--) {
        cin >> n >> c;
 
        for (int i = 1; i <= n; i++) cin >> arr[i];
        sort(arr+1, arr+n+1);
 
        cout << solve() << endl;
    }
 
    return 0;
}

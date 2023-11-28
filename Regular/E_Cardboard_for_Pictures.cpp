#include<bits/stdc++.h>

using namespace std;
#define int long long
#define endl "\n" 
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()

int n, area, sum1, sum2;

int search(vector<int>& arr) {
    int l = 1, h = 1e9, m, ans;

    while (l <= h) {
       m = (l+h) / 2;
       ans = 0;
       for (int i = 0; i < n; i++) {
            ans += (arr[i]+2*m) * (arr[i]+2*m);
            if (ans > area) break;
       }
       if (ans == area) break;
       else if (ans > area) h = m-1;
       else l = m+1;
    }
    return m;
}

void solve() {
    cin >> n >> area;
    sum1 = sum2 = 0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int ans = search(arr);

    cout << ans << endl;

}

int32_t main() {
    Faster;
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
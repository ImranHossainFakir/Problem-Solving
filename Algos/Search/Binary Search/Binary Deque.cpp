    #include "bits/stdc++.h"
         
    using namespace std;
     
    //#define int long long
    #define endl "\n"
    #define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define mem(a, b) memset(a, b ,sizeof(a))
    #define len(a) sizeof(a) / sizeof(int)
    #define all(x) (x).begin(), (x).end()
     
    int n, x;
    vector < int > v;
     
    int solve() {
        cin >> n >> x;
        v.resize(n+1);
     
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            v[i] = v[i] + v[i-1];
        }
     
        int op = INT_MAX;
     
        for (int i = 1; i <= n; i++) {
            int tem = 0, l = i, r = n, mid;
            while (l <= r) {
                mid = (l+r) / 2;
                if (x == v[mid] - v[i-1]) {
                    tem = mid - (i-1);
                }
                if (x >= v[mid] - v[i-1]) l = mid+1;
                else r = mid-1;
            }
           if (tem) op = min(op, n-tem);
        }
     
        return op == INT_MAX ? -1 : op;
    }
     
    int32_t main() {
        Faster;
     
        int t; cin >> t;
        while (t--) {
            cout << solve() << endl;
        }
     
        return 0;
    }

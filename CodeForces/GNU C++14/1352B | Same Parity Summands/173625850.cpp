#include "bits/stdc++.h"
 
using namespace std;
 
#define int long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define len(a) sizeof(a) / sizeof(int)
#define endl "\n"
#define pb push_back
#define mem(a, b) memset(a, b ,sizeof(a))
 
 
int32_t main() {
    IOS;
 
    int t; cin >> t;
 
    while (t--) {
        int n, k; cin >> n >> k;
 
        if (n < k) {
            cout << "NO" << endl;
        } else if ((n % 2 && k % 2) || (n % 2 == 0 && k % 2 == 0)) {
            cout << "YES" << endl;
            for (int i = 1; i < k; i++) cout << 1 << " ";
            cout << n - (k - 1) << endl;
        } else if (n % 2 == 0 && n / 2 >= k) {
            cout << "YES" << endl;
            for (int i = 1; i < k; i++) cout << 2 << " ";
            cout << n - (k - 1) * 2 << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
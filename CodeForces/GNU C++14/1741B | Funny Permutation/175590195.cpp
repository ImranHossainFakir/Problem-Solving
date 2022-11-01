#include "bits/stdc++.h"
     
using namespace std;
 
//#define int long long
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back // add in last position
#define pop pop_back() // remove last value
#define bk back() // return the last value
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define all(x) (x).begin(), (x).end()
 
int32_t main() {
    IOS;
 
    int t; cin >> t;
 
    while(t--) {
        int n; cin >> n;
 
        if (n == 3) {
            cout << -1 << endl;
            continue;
        }
 
        if (n % 2) {
            int tem = n;
            for (int i = 0; i < n / 2; i++, tem--) cout << tem << " ";
            for (int i = 1; i <= tem; i++) cout << i << " ";
            cout << endl;
        } else {
            for (int i = n; i > 0; i--) cout << i << " ";
            cout << endl;
        }
    }
 
    return 0;
}
#include "bits/stdc++.h"
     
using namespace std;
 
//#define int long long
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define pop pop_back() // remove last value
#define bk back() // return the last value
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define loop(b, e) for (int i = b; i < e; i++)
#define lc (n * 2)
#define rc ((n * 2) + 1)
#define mid ((e+b) / 2)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()
 
int32_t main() {
    IOS;
 
    int t; 
    cin >> t;
    while(t--) {
        int n; cin >> n;
        n = n - 3;
        cout << n / 3 - 1 << endl;
    }
    return 0;
}
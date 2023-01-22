#include "bits/stdc++.h"
     
using namespace std;
 
#define int long long
#define endl "\n"
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define all(x) (x).begin(), (x).end()
 
int32_t main() {
    Faster;
 
    int t; cin >> t;
    while (t--) {
        int n, mn = INT_MAX; cin >> n;
        vector < int > v(n);
        vector < pair < int, int > > v1(n);
 
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            v1[i] = {v[i], i};  
        }
        sort(all(v1));
 
        vector < pair < int, int > > ans;
 
        for (int i = 0; i < n-1; i++) {
            if (v1[i+1].first % v1[i].first) {
                int tem = (v1[i+1].first / v1[i].first + 1) * v1[i].first;
                pair < int, int > p = {v1[i+1].second+1, tem - v1[i+1].first};
                v1[i+1].first = tem;    
                ans.push_back(p);
            }
        }
        cout << ans.size() << endl;
        for (auto e : ans) {
            cout << e.first << " " << e.second << endl;
        }
 
    }
 
    return 0;
}

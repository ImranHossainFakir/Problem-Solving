#include "bits/stdc++.h"
     
using namespace std;
 
#define int long long
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
 
    while (t--) {
        int n, k; cin >> n >> k;
 
        int arr1[n];
        int arr2[n];
 
        for (int i = 0; i < n; i++) {
            int tem; cin >> tem;
            arr1[i] = tem;
            arr2[i] = tem;
        }
 
        int ans_will_be = 0;
 
        
        for (int i = 0; i < n; i++) {
            int ele = arr1[i];
            if (arr2[i%k] > ele) continue;
            else arr2[i%k] = ele;
            int sum = 0;
 
            for (int j = 0; j < k; j++) sum += arr2[j];
 
            ans_will_be = max(ans_will_be, sum);
        }
 
        cout << ans_will_be << endl;
 
    }
 
    return 0;
}
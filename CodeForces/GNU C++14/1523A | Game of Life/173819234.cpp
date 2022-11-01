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
 
int32_t main() {
    IOS;
 
    int tt; cin >> tt;
 
    while (tt--) {
        int n, m; cin >> n >> m;
        char chars[n+1];
        int arr_1[n+1];
        int arr_2[n+1];
 
        mem(arr_1, 0);
        mem(arr_2, 0);
 
        string s; cin >> s;
 
        for (int i = 1; i <= n; i++) chars[i] = s[i-1];
 
        int starting_index, ending_index;
        starting_index = 0;
        ending_index = 0;
 
        for (int i = 1; i <= n; i++) {
            if (chars[i] == '1') {
                starting_index = i;
                break;
            }
        }
 
        for (int i = n; i > 0; i--) {
            if (chars[i] == '1') {
                ending_index = i;
                break;
            }
        }
 
        if (starting_index == 0) {
            for (int i = 1; i <= n; i++) cout << chars[i];
            cout << endl;
            continue;
        }
 
        int cnt = 0;
 
        for (int i = starting_index; i <= n; i++) {
            if (chars[i] == '1') cnt = 0;
            else {
                cnt++;
                arr_1[i] = cnt;
            }
        }
 
        for (int i = ending_index; i > 0; i--) {
            if (chars[i] == '1') cnt = 0;
            else {
                cnt++;
                arr_2[i] = cnt;
            }
        }
 
        for (int i = 1; i <= n; i++) {
            int v1, v2;
            v1 = arr_1[i];
            v2 = arr_2[i];
            if (((v1 <= m && v1 != 0) || (v2 <= m && v2 != 0)) && v1 != v2) {
                chars[i] = '1';
            }
        }
 
        for (int i = 1; i <= n; i++) cout << chars[i];
            cout << endl;
    }
 
    return 0;
}
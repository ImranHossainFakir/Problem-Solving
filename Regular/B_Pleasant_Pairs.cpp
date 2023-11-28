#include<bits/stdc++.h>

using namespace std;
//#define int long long
#define endl "\n" 
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()

void solve() {
    int t; cin >> t;
    while (t--) {
        int n, cnt = 0; cin >> n;
        vector < int > arr(n+1);
        for (int i = 1; i <= n; i++) cin >> arr[i];

        for (int i = 1; i <= n; i++) {
            int tem = arr[i];
            int a = 2 * i + 1;
            int index = a/tem;
            index += min(1, a%tem); 
            index = index * tem - i;
            while (index <= n) {
                if (tem * arr[index] == i + index) cnt++;
                index += tem;
            }
        }
        cout << cnt << endl;
    }
}

int32_t main() {
    Faster;
    solve();   
    return 0;
}
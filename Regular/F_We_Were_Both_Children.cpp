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
        int n; cin >> n;
        set < int > s;
        vector < int > arr;
        for (int i = 0; i < n; i++) {
          int tem; cin >> tem;
          if (tem > n) continue;
          arr.push_back(tem);
          s.insert(tem);
        }

        vector < int > freq(n+1, 0);
        for (auto e : arr) freq[e]++;

        vector < int > mult(n+1, 0);
        for (auto hop : s) { 
            for (int j = 1; hop * j <= n; j++) { 
                mult[hop*j] = mult[hop*j] + freq[hop];
            }
        }

        int mx = 0;
        for (auto e : mult) mx = max(mx, e);
        cout << mx << endl;
    }
     
    int32_t main() {
        Faster;
        int t; cin >> t;
     
        while(t--) solve();   
        return 0;
    }
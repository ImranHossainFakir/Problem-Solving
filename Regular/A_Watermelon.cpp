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
    if (n%2 || n==2) cout << "NO" << endl;
    else cout << "YES" << endl;
    set<string > s;
    s.insert("hello");
    s.insert("world");
    for (auto e : s) cout << e << endl;
    int a = static_cast<int>(10e9);
    cout << a << endl;
}

int32_t main() {
    Faster;
    solve();
    return 0;
}
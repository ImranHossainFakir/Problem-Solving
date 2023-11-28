#include<bits/stdc++.h>

using namespace std;
//#define int long long
#define endl "\n" 
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()

void make_bigger(int &m, int n, int &i, int k) {
    while (m < n) {
        cout << 0;
        i++;
        if (i >= k) return;
        m *= 10;
    }
}

void solve() {
    int m, n, k, rem; cin >> m >> n >> k;
    cout << m/n << ".";
    m = m % n;
    for (int i = 0; i < k; ) {
        m *= 10;
        if (m < n) make_bigger(m, n, i, k);
        if (i >= k) return;
        cout << m/n;
        i++;
        m %= n;
    }
}

int32_t main() {
    Faster;
    
    solve();
    return 0;
}
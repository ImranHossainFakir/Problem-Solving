#include<bits/stdc++.h>

using namespace std;
#define int long long
#define endl "\n" 
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()

struct node {
    int sz, mn = 1, mx = 9;
};

void find_mn_mx(node& nd) {

    for (int i = 1; i < nd.sz; i++) {
        nd.mn *= 10;
        nd.mx = nd.mx * 10 + 9;
    }
    what_is(nd.mn);
    what_is(nd.mx);
}

void solve() {
    node a, b, c;
    int k, tem, sum; 
    cin >> a.sz >> b.sz >> c.sz >> k;
    find_mn_mx(a);
    find_mn_mx(b);
    find_mn_mx(c);
    tem = abs((a.mn + b.mn) - min(c.mx, b.mx)) + 1;
    what_is(tem);
    while (k >= tem) {
        k -= tem;
        tem--;
        a.mn++;
    }
    b.mn += (k-1);
    sum = (a.mn + b.mn);
    what_is(sum);
    what_is(b.mn);
    if (c.mn <= sum && sum <= c.mx) cout << a.mn << " + " << b.mn << " = " << sum << endl;
    else cout << -1 << endl;
}

int32_t main() {
    Faster;
    int t; cin >> t;
    while (t--)
    {
        solve();   
    }
    
    return 0;
}
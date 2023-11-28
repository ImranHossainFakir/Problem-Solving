#include<bits/stdc++.h>

using namespace std;
#define int long long
#define endl "\n" 
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()

const int N = 2e5+10;
const int s = 1 << 18;
int n, q;
vector < int > a;

struct node {
    int sum, pref;
    node(int sum, int pref) : sum(sum), pref(pref) {}
    node(int x = 0) : sum(x), pref(max(0LL, x)) {}
    friend node operator+(const node &a, const node &b) {
        return {a.sum + b.sum, max(a.pref, a.sum + b.pref)};
    }
} tt[s << 1];

void build(int nd = 1, int l = 1, int r = n) {
    if (l == r) {
        tt[nd] = node(a[l]);
        return; 
    }
    int m = (l + r) >> 1;
    int lt = nd << 1, rt = nd << 1 | 1;
    build(lt, l, m);
    build(rt, m + 1, r);
    tt[nd] = tt[lt] + tt[rt];
}

void update(int i, int x, int nd = 1, int l = 1, int r = n) {
    if (l == r) {
        tt[nd] = node(x);
        return;
    }

    int m = (l + r) >> 1;
    int lt = nd << 1, rt = nd << 1 | 1;
    if (i <= m) update(i, x, lt, l, m);
    else update(i, x, rt, m+1, r);
    tt[nd] = tt[lt] + tt[rt];
}

node query(int x, int y, int nd = 1, int l = 1, int r = n) {
    if (x > r || y < l) return 0;
    if (x <= l && r <= y) return tt[nd];
    int m = (l + r) >> 1;
    int lt = nd << 1, rt = nd << 1 | 1;
    node p1 = query(x, y, lt, l, m);
    node p2 = query(x, y, rt, m+1, r);
    return p1 + p2;
}

void solve() {
    cin >> n >> q;
    a.resize(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    build();
    for (int i = 0, t, x, y; i < q; i++) {
        cin >> t >> x >> y;
        if (t == 1) update(x, a[x] = y);
        else cout << query(x, y).pref << endl;
    }
}

int32_t main() {
    Faster;
    solve();   
    return 0;
}
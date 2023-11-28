#include<bits/stdc++.h>

using namespace std;
//#define int long long
#define endl "\n" 
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()
const int N = 1e5+9;
vector < int > tree;
vector < int > binary_num;

void update(int node, int l, int r, int x, int y) {
    if (x <= l && r <= y)  {
        tree[node]++;
        return;
    }
    if (y < l || r < x) return;
    int m, l_ch, r_ch;
    m = (l + r) >> 1;
    l_ch = node << 1;
    r_ch = (node << 1) + 1;
    update(l_ch, l, m, x, y);
    update(r_ch, m+1, r, x, y);
}

int query(int node, int l, int r, int ind, int cur_state) {
    if (l == r && r == ind) {
        return cur_state ? binary_num[ind] ^ 1 : binary_num[ind];
    }
    if (ind < l || r < ind) return 0;
    int m, l_ch, r_ch;
    m = (l + r) >> 1;
    l_ch = node << 1;
    r_ch = (node << 1) + 1;
    int ans = query(l_ch, l, m, ind, (cur_state+tree[l_ch]) % 2) | query(r_ch, m+1, r, ind, (cur_state+tree[r_ch]) % 2);
    return ans;
}

void solve() {
    int t; cin >> t;
    for (int cs = 1; cs <= t; ++cs) {
        cout << "Case " << cs << ":" << endl;
        string tem; cin >> tem;
        int q, len = tem.size();
        tree.resize(len << 2);
        binary_num.resize(len+1);
        cin >> q;
        for (int i = 0; i < len; i++) binary_num[i+1] = tem[i]-'0';

        while (q--) {
            char c; cin >> c;
            if (c == 'I') {
                int x, y; cin >> x >> y;
                update(1, 1, len, x, y);
            }
            else {
                int ind; cin >> ind;
                cout << query(1, 1, len, ind, tree[1]%2) << endl;
            }
        }
        binary_num.clear();
        tree.clear();
    }
}

int32_t main() {
    Faster;
    solve();
   
    return 0;
}
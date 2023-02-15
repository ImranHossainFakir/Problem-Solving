/*
* Problem link -> https://codeforces.com/problemset/problem/466/C
* From the given array we made a suffix[j].flag where av found and a preffix[j-1].cnt how many preffix we can made till j-1 which sum is equal to av. 
* time : O(n)
*/

#include "bits/stdc++.h"
     
using namespace std;

#define int long long
#define endl "\n"
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define all(x) (x).begin(), (x).end()

struct node
{
    int val, cnt, flag;
};

vector < int > v;
vector < node > sfx;
vector < node > pfx;
void make_suff(int av) {
    int len = sfx.size();
    int cnt = 0, sum = 0;
    for (int i = len-1; i >= 0; i--) {
        sum += v[i+1];
        if (sum == av && i > 1) {
            cnt++;
            sfx[i].flag = 1;
        } else sfx[i].flag = 0;
        sfx[i].cnt = cnt;
    }
}

void make_prfx(int av) {
    int len = pfx.size();
    int cnt = 0, sum = 0;
    for (int i = 0; i < len; i++) {
        sum += v[i+1];
        if (sum == av && i < len-2) {
            cnt++;
            pfx[i].flag = 1;
        } else pfx[i].flag = 0;
        pfx[i].cnt = cnt;
    }

}

void solve() {
    int n, av = 0, ans = 0; cin >> n;
    v.resize(n+2);
    sfx.resize(n);
    pfx.resize(n);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        av += v[i];
    }

    if (av % 3) {
        cout << ans << endl;
        return;
    }

    av /= 3;
    make_suff(av);
    make_prfx(av);

    for (int i = n-1; i > 1; i--) {
        if (sfx[i].flag) ans += pfx[i-2].cnt;
    }

    cout << ans << endl;

}

int32_t main() {
    Faster;
    solve();

    // for (auto e : pfx) cout << e.cnt << " ";
    // cout << endl;
    // for (auto e : sfx) cout << e.flag << " ";

    return 0;
}

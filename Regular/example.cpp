#include "bits/stdc++.h"

using namespace std;

//#define int long long
#define endl "\n"
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define all(x) (x).begin(), (x).end()


void solve() {
    int a, b, c; cin >> a >> b >> c;
    vector < int > arr{a, b, c};
    sort(all(arr));
    cout << arr[1] << endl;
}

void solve1() {
    double d1, d2, t1, t2;
    cin >> d1 >> t1 >> d2 >> t2;
    double v1 = d1 / t1;
    double v2 = d2 / t2;
    double ans = v1 - v2;
    cout << fixed << setprecision(4) << v2 << endl;
}

int32_t main() {
    Faster;
    // solve();
    solve1();
    return 0;
}
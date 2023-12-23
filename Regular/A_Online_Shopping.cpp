

/*

Problem link: https://atcoder.jp/contests/abc332/tasks/abc332_a
Time Complexity: 

*/


#include<bits/stdc++.h>

using namespace std;
//#define int long long
#define endl "\n" 
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()

void solve()
{
    int n, s, k, sum = 0; cin >> n >> s >> k;
    for (int i = 0; i < n; i++)
    {
        int p, q; cin >> p >> q;
        sum += p * q;
    }
    if (sum < s) sum += k;
    cout << sum << endl;
}
int32_t main() {
    Faster;

    solve();
    return 0;
}
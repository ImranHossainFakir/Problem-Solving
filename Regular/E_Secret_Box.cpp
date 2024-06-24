

/*

Problem link: https://codeforces.com/problemset/problem/1985/E
Time Complexity: 

*/


#include<bits/stdc++.h>

using namespace std;
#define int long long
#define endl "\n" 
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()

void solve()
{
    int x, y, z, k, mx = 0;
    cin >> x >> y >> z >> k;

    for (int a = x; a > 0; a--)
    {
        for (int b = y; b > 0; b--)
        {
            if (k % (a * b) == 0)
            {
                int c = k / (a * b); 
                mx = max(mx, (x-a+1) * (y-b+1) * (z-c+1));
            }
        }
    }

    cout << mx << endl;
}
int32_t main() {
    Faster;
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
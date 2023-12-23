

/*

Problem link: 
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
    int k, g, m; cin >> k >> g >> m;
    int mug = 0, glass = 0;
    while (k--) 
    {
        if (glass == g)
            glass = 0;
        else if (!mug)
            mug = m;
        else if (glass)
        {
            mug -= (g-glass);
            glass = g;
            
        }
        else 
        {
            glass = min(g, mug);
            mug = max(mug - g, 0);
        } 
    }
    cout << glass << " " << mug << endl;
}
int32_t main() {
    Faster;

    solve();
    return 0;
}
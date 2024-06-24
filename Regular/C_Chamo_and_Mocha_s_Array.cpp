

/*

Problem link: https://codeforces.com/problemset/problem/1975/C
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
    int n; cin >> n;
    vector < int > arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int mx = -1;

    for (int i = 0; i < n-2; i++)
    {
        vector < int > tem = {arr[i], arr[i+1], arr[i+2]};
        sort(all(tem));
        mx = max(mx, tem[1]);
    }

    if (n == 2)
        mx = min(arr[0], arr[1]);

    cout << mx << endl;
}
int32_t main() {
    Faster;
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
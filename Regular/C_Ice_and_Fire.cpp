

/*

Problem link: https://codeforces.com/problemset/problem/1774/C
Time Complexity: O(T * n);

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
    string str; cin >> str;
    vector < int > trailling_0_1(2);

    // picking all x from 2 to n
    for (int x = 2; x <= n; x++)
    {
        // taking trailling bit.
        int cur_bit = str[x-2]-48;

        // Counting the consicutive '0' or '1'
        trailling_0_1[cur_bit]++;
        trailling_0_1[cur_bit ^ 1] = 0;
        cout << x - (trailling_0_1[0] + trailling_0_1[1]) << " ";
    }
    cout << endl;
}
int32_t main() {
    Faster;
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
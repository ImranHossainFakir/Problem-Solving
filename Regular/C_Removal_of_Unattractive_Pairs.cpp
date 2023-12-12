

/*

Problem link: https://codeforces.com/contest/1907/problem/C
Time Complexity:

*/

#include <bits/stdc++.h>

using namespace std;
// #define int long long
#define endl "\n"
#define Faster                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define mem(a, b) memset(a, b, sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()

void solve()
{
    int n, mx = INT_MIN;;
    cin >> n;
    string str;
    cin >> str;
    vector<int> freq(26, 0);

    // to count frequency of the letters
    for (int i = 0; i < n; i++) {
        freq[str[i] - 'a']++;
        mx = max(mx, freq[str[i]-'a']);
    }

    // If mx covers the |n-mx| letters,
    // then answer will be mx - |n-mx|.
    // Otherwise n%2.
    int rem = n - mx;
    cout << (mx > rem ? mx - rem : n%2) << endl;
}
int32_t main()
{
    Faster;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
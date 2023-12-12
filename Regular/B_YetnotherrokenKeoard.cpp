

/*

Problem link: https://codeforces.com/contest/1907/problem/B
Time Complexity: O(t * n) n = lenght of string

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
    string str;
    cin >> str;
    vector < char > chars;
    int b = 0, B = 0;
    for (int i = str.size()-1; i >= 0; i--)
    {
        char cur = str[i];
        if (cur == 'B')
            B++;
        else if (cur == 'b')
            b++;
        else if ('A' <= cur && cur <= 'Z' && B)
            B--;
        else if ('a' <= cur && cur <= 'z' && b)
            b--;
        else
            chars.push_back(cur);
    }
    reverse(all(chars));
    for (auto c : chars)
        cout << c;
    cout << endl;
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
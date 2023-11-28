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
    int n, A, B, AWin, BWin;
    cin >> n;
    string str, ans = "?";
    cin >> str;
    for (int i = 1; i <= 20; i++)
    {
        A = B = AWin = BWin = 0;
        for (int j = 0; j < n; j++)
        {
            if (str[j] == 'A')
                A++;
            else
                B++;
            if (A == i)
            {
                AWin++;
                A = 0;
                B = 0;
            }
            else if (B == i)
            {
                BWin++;
                A = 0;
                B = 0;
            }
        }
        if (A == 0 && B == 0)
        {
            if (AWin > BWin && str[n - 1] == 'A')
            {
                ans = "A";
            }
            else if (BWin > AWin && str[n - 1] == 'B')
            {
                ans = "B";
            }
        }
    }
    cout << ans << endl;
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
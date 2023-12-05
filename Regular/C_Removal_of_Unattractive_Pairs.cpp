

/*

Problem link:
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
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<int> freq(26, 0);

    for (int i = 0; i < n; i++)
        freq[str[i] - 'a']++;

    int sum = 0;
    sort(all(freq));
    reverse(all(freq));

    for (int i = 0; i < 26; i++)
    {
        while (freq[i])
        {
            bool flag = true;
            for (int j = 25; j > i; j--)
            {
                if (freq[j])
                {
                    freq[i]--;
                    freq[j]--;
                    flag = false;
                }
                if (!freq[i])
                    break;
            }
            if (flag)
                break;
        }
    }
    for (auto v : freq) sum += v;
    cout << sum << endl;
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
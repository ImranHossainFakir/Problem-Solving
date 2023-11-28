#include <bits/stdc++.h>

using namespace std;
#define int long long
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> x(q);

    for (auto &e : a)
        cin >> e;
    for (auto &e : x)
        cin >> e;

    

    int cur_dv = INT_MAX;

    for (auto u : x)
    {
        if (cur_dv <= u)
            continue;
        cur_dv = u;
        for (int j = 0; j < n; j++)
        {
            if (a[j] % (1 << cur_dv) == 0)
                a[j] += (1 << (cur_dv - 1));
        }
    }

    for (auto u : a)
        cout << u << " ";
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
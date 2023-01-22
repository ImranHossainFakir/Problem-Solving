#include "bits/stdc++.h"

using namespace std;

#define int long long
#define endl "\n"
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define mem(a, b) memset(a, b, sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int give_me_series(int n)
{
    int series_sum, n_by_two;
    if (n % 2)
        n_by_two = (n - 1) / 2;
    else
    {
        n_by_two = n / 2;
        n = n - 1;
    }
    series_sum = (n % mod) * (n_by_two % mod);
    series_sum %= mod;
    series_sum = series_sum * 2 % mod;

    return series_sum;
}

int find_fact(int m) {
    int ser, fact = 1;
    ser = give_me_series(m);
        for (int i = 1; i <= m; i++)
        {
            ser = (i * ser) % mod;
        }
    return ser;
}

int32_t main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        int fact, ser_sum, m;
        cin >> m;

        fact = find_fact(m);

        cout << fact << endl;
    }

    return 0;
}

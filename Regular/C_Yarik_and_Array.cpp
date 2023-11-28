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

int solve()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (auto &e : a)
        cin >> e;

    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < a.size(); i++)
    {
        if (i != 0 && (abs(a[i]) % 2) == (abs(a[i - 1]) % 2))
            max_ending_here = a[i];
        else
            max_ending_here = max_ending_here + a[i];

        if (max_so_far < max_ending_here)
                max_so_far = max_ending_here;

        if (max_ending_here < 0)
                max_ending_here = 0;
    }
    return max_so_far;
}

int32_t main()
{
    Faster;
    int t; cin >> t;
    while(t--) cout << solve() << endl;
    return 0;
}
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

int solve()
{
    int n, x; cin >> n >> x;
    vector < int > points;
    points.push_back(0);
    for (int i = 0; i < n; i++) 
    {   
        int tem; cin >> tem;
        points.push_back(tem);
    }

    points.push_back(x);
    int fuel, tank = 100;

    for (int i = 1; i <= 100; i++)
    {
        int mx = i;
        fuel = i;
        for (int j = 0; ; j++)
        {

            if (j == n)
            {
                fuel -= 2 * (abs(points[j] - points[j+1]));
                break;
            }
            fuel -= (abs(points[j] - points[j+1]));
            fuel += i;
            mx = max(mx, fuel);
        }
        if (fuel >= 0)
            tank = min(tank, mx);
    }
    return tank;
}

int32_t main()
{
    Faster;
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    return 0;
}
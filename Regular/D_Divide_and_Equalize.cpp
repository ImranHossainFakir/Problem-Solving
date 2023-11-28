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


int v;

void count_prime_divisors(map < int, int >& divisors)
{
    int factor = 2;
    while (factor * factor <= v) 
    {
        while (v % factor == 0)
        {
            divisors[factor]++;
            v /= factor;
        }
        factor++;
    }
    if (v > 1) divisors[v]++;
}

bool solve()
{
    int n;
    cin >> n;
    map < int, int > divisors;
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        count_prime_divisors(divisors);
    }
    for (auto e : divisors)
        if (e.second % n != 0) 
            return false;
    

    return true;
}

int32_t main()
{
    Faster;
    int t; cin >> t;
    while (t--)
        cout << (solve() ? "YES" : "NO") << endl;
    return 0;
}
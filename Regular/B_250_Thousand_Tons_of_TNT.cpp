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

vector<int> countDivisors(int n)
{
    vector<int> div;
    for (int i = 1; i <= sqrt(n); i++)
    {

        if (n % i == 0)
        {
            // If divisors are equal,
            // count only one
            if (n / i == i)
                div.push_back(i);

            else // Otherwise count both
            {
                div.push_back(i);
                div.push_back(n / i);
            }
        }
    }
    sort(all(div));
    return div;
}

int solve()
{
    int n, len, ans = LONG_LONG_MIN;
    cin >> n;
    vector < int > numbers(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> numbers[i];
    }
    vector<int> divisors = countDivisors(n);
    len = divisors.size();

    for (int i = 0; i < len; i++)
    {
        int divisor = divisors[i], mx = LONG_LONG_MIN, mn = LONG_LONG_MAX, sum = 0;
        for (int j = 0; j < n;)
        {
            sum += numbers[j];
            j++;
            if (j % divisor == 0) 
            {
                mx = max(mx, sum);
                mn = min(mn, sum);
                sum = 0;
            }
        }
        ans = max(ans, (mx-mn));
    }
    return ans;
}
int32_t main()
{
    Faster;
    int t; cin >> t;
    while(t--) cout << solve() << endl;
    return 0;
}
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

vector<int> hudai(int l, int u)
{
    random_device rd;
    mt19937 gen(rd());
    
    vector < int > num;
    for (int i = l; i <= u; i++)
    {
        num.push_back(i);
    }

    shuffle(all(num), gen);
    

    return num;
}

void solve()
{
    int n, sum = 0; cin >> n;
    vector < int > num = hudai(1, n);
    vector < int > pref_sum(n+1);
    for (int i = 1; i <= n; i++)
    {
        pref_sum[i] = pref_sum[i-1] + num[i-1];
    }

    for (auto e : num) cout << e << " ";
    cout << endl;
    for (int i = 1; i <= n; i++) cout << pref_sum[i] << " ";
}

int32_t main()
{
    Faster;
    solve();
    return 0;
}
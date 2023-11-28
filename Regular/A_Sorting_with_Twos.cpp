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
int n;
vector<int> arr;

bool dako() {
    int j, i;
    for (i = 1; (int)pow(2, i+1) <= n; i++) {
        j = pow(2, i);
        while (++j < pow(2, i+1)) {
            if (arr[j] > arr[j + 1]) return false;
        }
    }
    j = pow(2, i);
    while (++j < n)
    {
        if (arr[j] > arr[j+1]) 
            return false;
    }
    return true;
}

void solve()
{
    cin >> n;
    arr.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    bool flag = dako();
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    arr.clear();
}

int32_t main()
{
    Faster;
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
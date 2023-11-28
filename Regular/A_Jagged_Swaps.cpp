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

void swap(int index, vector<int> &arr)
{
    int tem = arr[index + 1];
    arr[index + 1] = arr[index];
    arr[index] = tem;
}

bool check(vector<int> &arr)
{
    for (int i = 0; i < (int)arr.size() - 1; i++) 
    {
        if (arr[i] > arr[i+1])
            return false;
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &e : arr)
        cin >> e;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            if (arr[j - 1] < arr[j] && arr[j] > arr[j + 1])
                swap(j, arr);
        }
    }

    cout << (check(arr) ? "YES" : "NO") << endl;
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
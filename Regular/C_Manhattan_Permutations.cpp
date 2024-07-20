

/*

Problem link: https://codeforces.com/problemset/problem/1978/C
Time Complexity: O(t * n)

*/


#include<bits/stdc++.h>

using namespace std;
#define int long long
#define endl "\n" 
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()

void solve()
{
    int n, k; cin >> n >> k;
    int mxSum, term, a, l, m;
    m = n;

    term = n / 2;
    a = 1 + (n % 2);
    l = n % 2 ? term * 2 : term * 2 - 1;
    mxSum = (term * (a + l));

    if (mxSum < k || k % 2)
    {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    vector < int > arr(n+1);
    for (int i = 1; i <= n; i++)
        arr[i] = i;
    
    int b = 1;
    while (k > 0)
    {
        int tem = (n - b) * 2;
        if (tem <= k)
            swap(arr[n--], arr[b++]);
        else
            swap(arr[b], arr[k/2+b]);

        k -= tem;
    }

    for (int i = 1; i <= m; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int32_t main() {
    Faster;
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
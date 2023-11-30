

/*

Problem link: https://codeforces.com/contest/1903/problem/A
Time Complexity: O(t * n)

*/


#include<bits/stdc++.h>

using namespace std;
//#define int long long
#define endl "\n" 
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()

// checking is array already sorted
bool is_asscending(vector < int > &arr)
{
    for (int i = 0; i < (int)arr.size()-1; i++)
        if (arr[i] > arr[i+1])
            return false;
    return true;
}

void solve()
{
    int n, k; cin >> n >> k;
    vector < int > arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    bool flag = is_asscending(arr);

    // array is not sorted in asscending order && k = 1 then ans is "NO"
    if (!flag && k == 1)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}
int32_t main() {
    Faster;
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
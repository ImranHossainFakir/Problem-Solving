

/*

Problem link: 
Time Complexity: 

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

const int N = 1e5+3;
vector < int > pre_sum(N, 0);

void make_pre_sum_arr()
{
    pre_sum[1] = 1;
    for (int i = 2; i < N; i++)
        pre_sum[i] = pre_sum[i-1] + i;
}

void solve()
{
    int pack, n, sum = 0;
    cin >> n >> pack;

    for (int i = pack, v = 1; i <= n; i += pack, v++)
        sum += v * (pre_sum[i] - pre_sum[i-pack]);
    sh
    cout << sum << endl;
}

int32_t main() {
    Faster;

    make_pre_sum_arr();

    int t; cin >> t;
    while (t--) solve();
    return 0;
}
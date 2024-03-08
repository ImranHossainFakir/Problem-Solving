

/*

Problem link: https://codeforces.com/problemset/problem/558/A
Time Complexity: O(n log n)

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

vector < pair < int, int > > positions[2];

int make_sum(int dir)
{
    
    int indexs[] = {0, 0}, sum = 0;

    // If dir = 1, then we will continue moving in the right direction.
    // Otherwise, we will proceed in the left direction.
    while (indexs[dir] < (int)positions[dir].size())
    {
        sum += positions[dir][indexs[dir]++].second;
        dir ^= 1;  
    }
    return sum;
}

void solve()
{
    int n; cin >> n;

    for (int i = 0; i < n; i++)
    {
        int tem, v; cin >> tem >> v;
        if (tem < 0) positions[0].push_back({-1*tem, v});
        else positions[1].push_back({tem, v});
    }

    // sorting based on positions of the tree.
    sort(all(positions[1]));
    sort(all(positions[0]));

    int mx = max(make_sum(1), make_sum(0));

    cout << mx << endl;

}


void hudai() {
    int n, pst = 0, neg = 0, sum = 0; cin >> n;
    vector < pair < int, int > > x, y;
    for (int i = 0; i < n; i++)
    {
        int pos, val; cin >> pos >> val;
        if (pos < 0)
        {
            y.push_back(make_pair(-pos, val));
            neg++;
        }
        else 
        {
            x.push_back(make_pair(pos, val));
            pst++;
        }
    }

    sort(all(x));
    sort(all(y));

    for (int i = 0; i < min(pst, neg); i++)
            sum += x[i].second + y[i].second;
    if (pst < neg)
        sum += y[pst].second;
    else if (pst > neg)
        sum += x[neg].second;
    cout << sum << endl;
}

int32_t main() {
    Faster;
    
    // solve();
    hudai();
    return 0;
}
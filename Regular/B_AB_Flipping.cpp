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

void _swap(vector < pair < int, int > > &seg, string &str)
{
    int len = str.length();

    for (int i = 0; i < (int)seg.size(); i++) 
    {
        int s = seg[i].first, e = seg[i].second;
        if (e == len-1)
            break;
        if (str[e+1] == 'B')
            swap(str[s], str[e+1]);
    }
}

void make_seg(vector < pair < int , int > > &seg, string &str, int &ans, vector < bool > &vis) 
{
    int len = str.length();

    for (int i = 0, s = -1; i < len; i++) 
    {
        if (str[i] == 'A')
        {
            if (s == -1)
                s = i;
        }
        else if (s != -1) {
            seg.push_back({s, i-1});
            s = -1;
        }
        if (i == len-1 && s != -1)
            seg.push_back({s, i});

    }
}

int solve()
{
    int n, cntA = 0, ans = 0;
    cin >> n;
    string str;
    cin >> str;
    vector < pair < int, int > > seg;
    vector < bool > vis(n, false);

    make_seg(seg, str, ans, vis);

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'A')
        {
            vis[i] = true;
            cntA++;
        }
        if (str[i] == 'B' && cntA)
        {
            ans += cntA;
            vis[i-1] = true;
            while (++i < str.length() && str[i] == 'B')
            {
                vis[i-1] = true;
                ans++;
            }
            cntA = 0;
            i--;
        }
    }

    _swap(seg, str);

    for (int i = 0; i < str.length()-1; i++) 
    {
        if (!vis[i] && str[i] == 'A' && str[i+1] == 'B')
        {
            vis[i] = true;
            swap(str[i], str[i+1]);
            ans++;
        }
    }
   
    return ans;
}

int32_t main()
{
    Faster;
    int t;
    cin >> t;
    while (t--)
        cout << solve() << endl;
    return 0;
}
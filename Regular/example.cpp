#include "bits/stdc++.h"

using namespace std;

#define int long long
#define endl "\n"
#define Faster                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define mem(a, b) memset(a, b, sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define all(x) (x).begin(), (x).end()

const int N = 21;
int c, r;
int x[] = {1, -1, 0, 0};
int y[] = {0, 0, 1, -1};

vector < vector < pair < int, int > > > adj(N, vector<pair<int, int>>(N));


pair < int, int > start_pos(string grid[])
{
    for (int i = 0; i < r; i++)
        for (int j = 0;j < c; j++)
            if (grid[i][j] == '@')
                return make_pair(i, j);
}

bool isOk(int a, int b)
{
    return -1 < a && a < r && -1 < b && b < c;
}

void bfs(string grid[])
{
    int ans = 0;
    queue < pair < int, int > > q;
    vector < vector < bool > > vis(N, vector < bool >(N, false));
    // inserting the start position
    q.push(start_pos(grid));

    while (!q.empty())
    {
        pair < int, int > frnt = q.front(); q.pop();
        vis[frnt.first][frnt.second] = true;

        for (int i = 0; i < 4; i++)
        {   
            int a = frnt.first+x[i], b = frnt.second+y[i];
            if (isOk(a, b) && !vis[a][b] && grid[a][b] == '.')
            {
                // cerr << "pushing " << a << " " << b <<
                q.push(make_pair(a, b));
                ans++;
            }
        }
    }
    cout << ans << endl;
}

void solve()
{
    cin >> c >> r;
    string grid[r];
    for (int i = 0; i < r; i++)
        cin >> grid[i];
    bfs(grid);
}

int32_t main()
{
    Faster;
    int t; cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}
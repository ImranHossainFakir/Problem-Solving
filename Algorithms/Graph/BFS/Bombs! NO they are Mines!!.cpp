/*
This is a simple bfs problem.
Since it is a graph problem and 
the given graph may or may not be a tree, so we always use BFS to find the shortesh path
*/

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

const int N = 1e3+10;
int bombRgn[N][N], vis[N][N];

int row, col, sRow, sCol, dRow, dCol, depth;
int x[] = {-1, 1, 0, 0};
int y[] = {0, 0, -1, 1};

struct node
{
    int r, c;
    node(int r, int c) : r(r), c(c) {}
};

bool can_I_move(int r, int c)
{
    return (0 <= r && r < row && 0 <= c && c < col && bombRgn[r][c] != 1 && vis[r][c] == 0);
}

void bfs()
{
    queue<node> q;
    q.push(node(sRow, sCol));
    vis[sRow][sCol] = 1;

    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            node u = q.front();
            q.pop();

            if (u.r == dRow && u.c == dCol)
                return;
            // what_is(u.r);
            // what_is(u.c);

            for (int i = 0; i < 4; i++)
            {
                int a = u.r + x[i];
                int b = u.c + y[i];
                // If robot can move then pushing the
                // cell and marking it as visited.

                if (can_I_move(a, b))
                {
                    vis[a][b] = 1;
                    q.push(node(a, b));
                }
            }
        }
        depth++;
    }
}

void make_Bomb_Region()
{
    int bombRows;
    cin >> bombRows;

    // Marking the bomb positions
    for (int i = 0; i < bombRows; i++)
    {
        int rBm, qunt;
        cin >> rBm >> qunt;
        for (int j = 0; j < qunt; j++)
        {
            int cBm;
            cin >> cBm;
            bombRgn[rBm][cBm] = 1;
        }
    }
}

void solve()
{
    while (cin >> row >> col, row || col)
    {
        mem(vis, 0);
        mem(bombRgn, 0);

        // Marking the bomb positions
        make_Bomb_Region();

        cin >> sRow >> sCol;
        cin >> dRow >> dCol;

        depth = 0;
        bfs();
        cout << depth << endl;
    }
}

int32_t main()
{
    Faster;
    solve();
    return 0;
}

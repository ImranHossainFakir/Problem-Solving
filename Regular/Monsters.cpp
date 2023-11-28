#include<bits/stdc++.h>

using namespace std;
//#define int long long
#define endl "\n" 
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()


struct node {
    int x, y;
    node() : x(0), y(0) {}
    node(int _x, int _y) {
        x = _x;
        y = _y;
    }
};


const int N = 1e4+2;

int x[] = {1, -1, 0, 0};
int y[] = {0, 0, 1, -1};
char chars[] = {'D', 'U', 'R', 'L'};
vector < vector < int > > vis(N, vector < int > (N));
vector < string > grid;
vector < vector < pair < node, char > > > parents(N, vector < pair < node, char > > (N));
int n, m;
node Wall = node(-1, -1);

bool isValid(int r, int c) {
    return grid[r][c] != 'M' 
        && grid[r][c] != '#'
        && !vis[r][c];
}

bool isWall(int r, int c) {
    return c == -1 || 
           r == -1 ||
           r == n ||
           c == m;
}

bool bfs(int a, int b) {
    queue < node > q;
    q.push(node(a, b));
    vis[a][b] = 1;

    while (!q.empty())
    {
        node u = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int r = u.x + x[i];
            int c = u.y + y[i];
            if (isValid(r, c)) 
            {   

                if (isWall(r, c))
                {
                    Wall = node(u.x, u.y);
                    return true;
                }
                vis[r][c] = 1;
                parents[r][c] = make_pair(node(u.x, u.y), chars[i]);
                q.push(node(r, c));
            }
        }
    }
    return false;
}

void printAns() {
    vector < char > cs;
    int r = Wall.x, c = Wall.y;
    while (r != -1 && c != -1)
    {
        cs.push_back(parents[r][c].second);
        node tem = parents[r][c].first;
        r = tem.x;
        c = tem.y;
    }
    
    reverse(all(cs));

    cout << (int)cs.size()-1 << endl;
    for (int i = 1; i < (int)cs.size(); i++) cout << cs[i];
    cout << endl;
}

node findSNode() {
    int x, y;
    x = y = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A')
            {
                x = i;
                y = j;
            }
        }
    }
    return node(x, y);
}

void solve() {
    cin >> n >> m;
    grid.resize(n);
    parents.resize(n+1);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    node sNode = findSNode();
    parents[sNode.x][sNode.y] = make_pair(node(-1, -1), 'C');

    bool flag = bfs(sNode.x, sNode.y);
    if (flag) {
        cout << "YES" << endl;
        printAns();
    } else {
        cout << "NO" << endl;
    }
}

int32_t main() {
    Faster;
    solve();   
    return 0;
}
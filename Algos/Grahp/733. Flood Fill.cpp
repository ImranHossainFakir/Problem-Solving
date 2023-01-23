/*
* Problem link -> https://leetcode.com/problems/flood-fill/description/
* Here we used x and y vectors for traversing 4-directional sites. If we have go to 8-directional sites then we can use x = {-1, 1, 0, 0, -1, -1, 1, 1} and 
* y = {0, 0, -1, 1, -1, 1, -1, 1}. 
* Time = 
*/


#include "bits/stdc++.h"

using namespace std;

// #define int long long
#define endl "\n"
#define Faster                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define mem(a, b) memset(a, b, sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define all(x) (x).begin(), (x).end()

vector<vector<int>> vis;
vector<int> x = {-1, 1, 0, 0};
vector<int> y = {0, 0, -1, 1};
int m, n;
bool is_ok(int r, int c)
{
    return -1 < r && r < m && -1 < c && c < n;
}
void dfs(vector<vector<int>> &image, int sr, int sc, int col)
{

    if (vis[sr][sc])
        return;
    vis[sr][sc] = true;

    for (int i = 0; i < 4; i++)
    {
        int r = sr + x[i], c = sc + y[i];
        if (is_ok(r, c) && image[r][c] == image[sr][sc])
            dfs(image, r, c, col);
    }
    image[sr][sc] = col;
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    m = image.size();
    n = image[0].size();
    for (int i = 0; i < m; i++)
    {
        vector<int> tem;
        for (int j = 0; j < n; j++)
            tem.push_back(0);
        vis.push_back(tem);
    }

    dfs(image, sr, sc, color);

    return image;
}

int32_t main()
{
    Faster;
    int sr, sc, col;
    vector<vector<int>> image;
    for (int i = 0; i < 2; i++)
    {
        vector<int> tem;
        for (int j = 0; j < 3; j++)
        {
            int val;
            cin >> val;
            tem.push_back(val);
        }
        image.push_back(tem);
    }

    cin >> sr >> sc >> col;

    vector<vector<int>> ans = floodFill(image, sr, sc, col);

    for (auto v : ans)
    {
        for (auto e : v)
            cout << e << " ";
        cout << endl;
    }

    return 0;
}

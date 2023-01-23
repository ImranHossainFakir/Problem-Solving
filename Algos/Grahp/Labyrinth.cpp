#include "bits/stdc++.h"
     
using namespace std;
 
//#define int long long
#define endl "\n"
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define all(x) (x).begin(), (x).end()
 
const int N = 1e6+9;
const int Row = 1e3+9;
 
string s[Row];
int row, col, inx; 
bool vis[N];
char path[N];
int p[N];
queue < int > q;
 
bool ok(int i, int j) {
    int ind = i * col + j;
    return -1 < i && i < row && -1 < j && j < col && ind < row * col && s[i][j] != '#' && !vis[ind];
}
 
 
void assing(int par, int child, char c) {
    //cout << child / col << ", " << child % col << " are assinged" << endl;
    p[child] = par;
    path[child] = c;
    q.push(child);
}
 
int search_from(int i, int j) {
 
    if (s[i][j] == 'B') return i * col + j;
    int child, par = i * col + j;
 
    if (ok(i+1, j)) { // Down
        child = (i+1) * col + j;
        assing(par, child, 'D');
    }
    if (ok(i-1, j)) { // Upper
        child = (i-1) * col + j;
        assing(par, child, 'U');
    }
    if (ok(i, j+1)) { // Right
        child = i * col + (j+1);
        assing(par, child, 'R');
    }
    if (ok(i, j-1)) { // Left
        child = i * col + (j-1);
        assing(par, child, 'L');
    }
 
 
    return -1;
}
 
void print_ans() {
    stack < char > ans;
    while (inx != -1) {
        ans.push(path[inx]);
        inx = p[inx];
    }
 
    ans.pop();
    cout << "YES" << endl << ans.size() << endl;
    while (!ans.empty()) {
        cout << ans.top();
        ans.pop();
    }
}
 
void bfs(int ind) {
    q.push(ind);
    inx = -1;
    p[ind] = -1;
 
    while (!q.empty() && inx == -1) {
        int v = q.front();
        q.pop();
 
        if (!vis[v]) {
            vis[v] = true;
            int i = v / col, j = v % col;
 
            //cout << "Searcing from " << i << ", " << j << endl;
 
            inx = search_from(i, j);
        }
    }
    if (inx == -1) cout << "NO" << endl;
    else print_ans();
 
    return;
}
 
void solved() {
    bool flag = false;
 
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (s[i][j] == 'A') { 
                bfs(i * col + j);
                flag = true;
            }
            if (flag) break;
        }
        if (flag) break;
    }
    return;
}
 
 
int32_t main() {
    Faster;
    cin >> row >> col;
 
    for (int i = 0; i < row; i++) cin >> s[i];
    for (int i = 0; i < col * row; i++) {
        vis[i] = false;
        path[i] = 0;
    }
    solved();
 
    return 0;
}

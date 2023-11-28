#include<bits/stdc++.h>

using namespace std;
//#define int long long
#define endl "\n" 
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()

int x[] = {0, 0, -1, 1, -1, 1};
int y[] = {-1, 1, 0, 0, -1, 1};
bool is_ok(int x, int y) {
    return 0 <= x && x < 3 && 0 <= y && y < 3;
}

string is_match(int a, int b, vector <string>& str) {
    char c = str[a][b];
    for (int i = 0; i < 6; i+=2) {
        int x1, x2, y1, y2;
        x1 = a+x[i];
        y1 = b+y[i];
        x2 = a+x[i+1];
        y2 = b+y[i+1];
        if (is_ok(x1, y1) && is_ok(x2, y2) && str[x1][y1] == c && str[x2][y2] == c) {
            string ans(1, c);
            return ans;
        }
    }
    return ".";
}


void solve() {
    int t; cin >> t;
    while (t--) {
        vector < string > str(3);
        string ans;
        for (int i = 0; i < 3; i++) cin >> str[i];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                ans = is_match(i, j, str);
                if (ans.compare(".")) break;
            }
            if (ans.compare(".")) break;
        }
        cout << (ans.compare(".") ? ans : "DRAW") << endl;
        str.clear();
    }
}

int32_t main() {
    Faster;
    solve();   
    return 0;
}
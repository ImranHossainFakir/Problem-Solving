#include<bits/stdc++.h>

using namespace std;
//#define int long long
#define endl "\n" 
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()
vector < string > str(3);
char ans;

void find_matches(char c) {
    for (int i = 0; i < 3; i++) {
        if (str[i][0] == c && str[i][1] == c && str[i][2] == c) 
            ans = c;
        if (str[0][i] == c && str[1][i] == c && str[2][i] == c) 
            ans = c;
    }
    if (str[0][0] == c && str[1][1] == c && str[2][2] == c) ans = c;
    if (str[0][2] == c && str[1][1] == c && str[2][0] == c) ans = c;
}

void solve() {
    int t; cin >> t;
    while (t--) {
        str.resize(3);
        for (int i = 0; i < 3; i++) cin >> str[i];
        char ans = '.';
        find_matches('X');
        find_matches('O');
        find_matches('+');

        cout << (ans == '.' ? "DRAW" :  string(1, ans)) << endl;
        str.clear();
    }
}

int32_t main() {
    Faster;
    solve();   
    return 0;
}
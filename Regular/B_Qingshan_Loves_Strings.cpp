#include<bits/stdc++.h>

using namespace std;
//#define int long long
#define endl "\n" 
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()



bool isPossible(string& t) {

    for (int i = 0; i < t.length()-1; i++) {
        if (t[i] == t[i+1])
            return false;
    }

    return true;
}
void solve() {
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;

    if (isPossible(s)) {
        cout << "YES" << endl;
        return;
    }


    if (!isPossible(t) || t[0] != t[t.length()-1]) {
        cout << "NO" << endl;
        return;
    }

    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == s[i+1] && t[0] == s[i])
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int32_t main() {
    Faster;
    int t; cin >> t;
    while(t--)solve();
    return 0;
}
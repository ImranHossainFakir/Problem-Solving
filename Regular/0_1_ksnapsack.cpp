#include<bits/stdc++.h>

using namespace std;
//#define int long long
#define endl "\n" 
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()

int dp(int current_W, vector <int> profit, vector <int> wigth, int n) {
    if (n == 0 || current_W == 0) return 0;

    if (wigth[n-1] > current_W) return dp(current_W, profit, wigth, n-1);
    else return max(profit[n-1] + dp(current_W-wigth[n-1], profit, wigth, n-1), dp(current_W, profit, wigth, n-1));
}

void solve() {
    string st = "hello world";
    bool flag = true;
    for (int i = 0; i < (int)st.size(); i++) {
        if (flag) {
            st[i] = toupper(st[i]);
            flag = false;
        }
        else if (st[i] == ' ') flag = true;
    }
    cout << st << endl;
}

int32_t main() {
    Faster;
    solve();   
    return 0;
}
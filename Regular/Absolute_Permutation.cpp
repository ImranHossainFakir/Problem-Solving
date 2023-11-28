#include<bits/stdc++.h>

using namespace std;
//#define int long long
#define endl "\n" 
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()

bool can_make_per(int n, int k, vector<int>& ans) {
    vector < int > have_or_not(n+1);
    for (int i = 1; i <= n; i++) {
        if (1 <= i-k && !have_or_not[i-k]) {
            have_or_not[i-k] = 1;
            ans.push_back(i-k);
        } 
        else if (i+k <= n && !have_or_not[i+k]) {
            have_or_not[i+k] = 1;
            ans.push_back(i+k);
        }
        else return false;
    }
    return true;
}

vector<int> absolutePermutation(int n, int k) {
    vector < int > ans;
    bool flag = can_make_per(n, k, ans);
    if (flag) return ans;
    return {-1};
}

int32_t main() {
    Faster;
    int n, k;
    cin >> n >> k;
    vector < int > result = absolutePermutation(n, k);
    for (auto e : result) cout << e << " ";
    return 0;
}
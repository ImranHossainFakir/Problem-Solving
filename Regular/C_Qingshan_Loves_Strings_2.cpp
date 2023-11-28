#include<bits/stdc++.h>

using namespace std;
//#define int long long
#define endl "\n" 
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()

bool is_zero_one_same(string& str) {
    int cnt1, cnt2;
    cnt1 = cnt2 = 0;

    for (int i = 0; i < (int)str.size(); i++) {
        cnt1 += str[i] == '0';
        cnt2 += str[i] == '1';
    }

    return cnt1 != cnt2;
}

void solve() {
    int n; cin >> n;
    string str; cin >> str;

    if (is_zero_one_same(str)) {
        cout << -1 << endl;
        return;
    }

    vector < int > post;
    deque < int > q;

    for (int i = 0; i < n; i++) 
        q.push_back(str[i]-48);
    
    int f = 0, l = n;
    while (!q.empty())
    {
        if (q.front() == q.back()) {
            if (q.front() == 0) {
                q.push_back(0);
                q.push_back(1);
                post.push_back(l-f);
            } else {
                q.push_front(1);
                q.push_front(0);
                post.push_back(f);
            }
            l+=2;
        }

        while (!q.empty() && q.front() != q.back()) {
            q.pop_front();
            q.pop_back();
            f++;
        }
    }
    cout << (int)post.size() << endl;
    for (auto e : post) cout << e << " ";
    cout << endl;
}

int32_t main() {
    Faster;
    int t; cin >> t;
    while(t--)solve();   
    return 0;
}
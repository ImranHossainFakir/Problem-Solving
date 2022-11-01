#include "bits/stdc++.h"
     
using namespace std;
 
//#define int long long
#define endl "\n"
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define all(x) (x).begin(), (x).end()
 
int32_t main() {
    Faster;
    
    string s; cin >> s;
 
    stack < char > st;
 
    int len = s.length();
    int cnt = 0;
 
    for (int i = 0; i < len; i++) {
        if (!st.empty() && s[i] == st.top()) {
            cnt++;
            st.pop();
        } else {
            st.push(s[i]);
        }
    }
 
    if (cnt % 2) cout << "Yes" << endl;
    else cout << "No" << endl;
 
    return 0;
}
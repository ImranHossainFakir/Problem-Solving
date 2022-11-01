#include "bits/stdc++.h"
     
using namespace std;
 
//#define int long long
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back // add in last position
#define pop pop_back() // remove last value
#define bk back() // return the last value
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define all(x) (x).begin(), (x).end()
 
int32_t main() {
    IOS;
    int t; cin >> t;
 
    while(t--) {
        string s1, s2; cin >> s1 >> s2;
        int l1, l2;
        l1 = s1.length();
        l2 = s2.length();
 
        if (s1[l1-1] == 'S') {
            if (s2[l2-1] == 'S') {
                if (l1 == l2)cout << "=" << endl;
                else if (l1 > l2) cout << "<" << endl;
                else cout << ">" << endl;
            } else {
                cout << "<" << endl;
            }
        }
        else if (s1[l1-1] == 'M') {
            if (s2[l2-1] == 'S') cout << ">" << endl;
            else if (s2[l2-1] == 'L') cout << "<" << endl;
            else cout << "=" << endl;
        }
        else {
            if (s2[l2-1] == 'L') {
                if (l1 == l2)cout << "=" << endl;
                else if (l1 < l2) cout << "<" << endl;
                else cout << ">" << endl;
            }
            else {
                cout << ">" << endl;
            }
        }
    }
 
    return 0;
}
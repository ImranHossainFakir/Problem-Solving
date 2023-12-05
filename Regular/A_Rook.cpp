

/*

Problem link: 
Time Complexity: 

*/


#include<bits/stdc++.h>

using namespace std;
//#define int long long
#define endl "\n" 
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()

void solve()
{
    string pos;
    cin >> pos;
    char col[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

    for (int i = 1; i <= 8; i++) {
        if (i == pos[1]-48)
            continue;
        cout << pos[0] << i << endl;
    }

    for (int i = 0; i < 8; i++)
    {
        if (pos[0] == col[i])
            continue;
        cout << col[i] << pos[1] << endl;
    }   
}
int32_t main() {
    Faster;
    int t; cin >> t;   
    while (t--) solve();
    return 0;
}
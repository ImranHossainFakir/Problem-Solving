#include "bits/stdc++.h"

using namespace std;

//#define int long long
#define endl "\n"
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define all(x) (x).begin(), (x).end()


void A() {
    int x, y, w, z; cin >> x >> y >> w >> z;
    cout << (x+y) << " " << (w-z) << " " << (x*z) << " " << (w/y) << endl;
}



int32_t main() {
    Faster;
    A();
    return 0;
}
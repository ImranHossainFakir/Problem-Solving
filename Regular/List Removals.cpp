#include<bits/stdc++.h>

using namespace std;
//#define int long long
#define endl "\n" 
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;


template <class T>

using Tree =

    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    

    int n; cin >> n;
    Tree < int > st;
    vector < int > p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        st.insert(i);        
    }
    for (int i = 0; i < n; i++) {
        int ind; cin >> ind;
        ind--;
        int pos = *st.find_by_order(ind);
        st.erase(pos);
        cout << p[pos] << "";
    } 
}

void hudai() {
    int a, b; cin >> a >> b;
    cout << a + b;
}

int32_t main() {
    Faster;
    hudai();
    return 0;
}

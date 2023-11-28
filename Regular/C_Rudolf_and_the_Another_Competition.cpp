#include<bits/stdc++.h>

using namespace std;
#define int long long
#define endl "\n" 
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()

struct node {
    int solved, penalty, id;
};

bool com(node& a, node& b) {
    if (a.solved != b.solved) return a.solved > b.solved;
    return a.penalty <= b.penalty;
}

void solve() {
    int n, m, h; cin >> n >> m >> h;
    vector < vector < int > > participants(n, vector<int>(m));
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            int a; cin >> a;
            participants[j][i] = a;
        }
        sort(all(participants[j]));
    }

    vector < node > ranks(n);

    ranks[0].id = 1;
    for (int i = 0; i < n; i++) {
        int time = h, starting = 0;
        ranks[i].id = i;
        vector < int > v = participants[i];
        for (int j = 0; j < m; j++) {
            if (v[j] > time) break;
            ranks[i].solved++;
            ranks[i].penalty += starting + v[j];
            starting += v[j];
            time -= v[j];
        }
        // cout << ranks[i].solved << " " << ranks[i].penalty << " " << ranks[i].id << endl;
    }
    
    sort(all(ranks), com);
    for (int i = 0; i < n;i++) {
        if (ranks[i].id == 0) {
            cout << i+1 << endl;
            break;
        }
    }

}

int32_t main() {
    Faster;
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
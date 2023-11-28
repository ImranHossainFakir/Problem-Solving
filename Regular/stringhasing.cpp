#include<bits/stdc++.h>

using namespace std;
#define int long long
#define endl "\n" 
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()

int computeHash(string const& s) {
    const int p = 31;
    const int m = 1e9+9;
    int hash_value = 0;
    int p_pow = 1;

    for (auto c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m; // if we Precompute the powers of  p  might give a performance boost.
    }

    return hash_value;
}

vector < vector < int > > group_inditical_string(vector < string > const& s) {
    int n = (int)s.size();
    vector < pair < int, int > > hashes(n);
    for (int i = 0; i < n; i++) hashes[i] = {computeHash(s[i]), i};

    sort(all(hashes));

    vector < vector < int > > groups;
    for (int i = 0; i < n; i++) {
        if (i == 0 || hashes[i-1].first != hashes[i].first)
            groups.emplace_back();
        groups.back().push_back(hashes[i].second);
    }

    return groups;
}

int32_t main() {
    Faster;
    vector < string > v{"imran", "hossain", "imran", "imran", "mizan", "mizan"};

    vector < vector < int > > groups = group_inditical_string(v);

    for (auto vec : groups) {
        for (auto e : vec) cout << v[e] << " ";
        cout << endl;
    }

    return 0;
}
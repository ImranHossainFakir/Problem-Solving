#include <bits/stdc++.h>

using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>

#define int long long
#define endl "\n"
#define Faster                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define mem(a, b) memset(a, b, sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()

int n;
const int p = 31, p2 = 53;
const int m = 1e9 + 9, m2 = 1e18;

vector<int> bad_cnt;
vector<int> suff_hash_1;
vector<int> suff_hash_2;
vector<int> pow_p;
vector<int> pow_p1;

struct PairHash {
    template <typename T, typename U>
    std::size_t operator()(const std::pair<T, U>& p) const {
        auto hash1 = std::hash<T>{}(p.first);
        auto hash2 = std::hash<U>{}(p.second);

        // Combine the hashes using a simple hash function
        return hash1 ^ hash2;
    }
};

struct PairEqual {
    template <typename T, typename U>
    bool operator()(const std::pair<T, U>& lhs, const std::pair<T, U>& rhs) const {
        return lhs.first == rhs.first && lhs.second == rhs.second;
    }
};

void construct(string s, string good_bad)
{
    int bad = 0;

    for (int i = 0; i < n; i++)
    {
        int tem = stoi(good_bad.substr(s[i] - 'a', 1));
        bad += tem ^ 1; // counting cumulitive sum of bad char
        bad_cnt[i + 1] = bad;
    }
}

void precomput_pow_p()
{
    pow_p[0] = 1;
    pow_p1[0] = 1;
    for (int i = 1; i < n; i++) {
        pow_p[i] = (pow_p[i-1] * p) % m;
        pow_p1[i] = (pow_p1[i-1] * p2) % m2;
    }
}

void comput_hash(string s)
{
    for (int i = 1; i < n; i++) {
        suff_hash_1[i] = (suff_hash_1[i-1] + (s[i]-'a'+1) * pow_p[i]) % m; 
        suff_hash_2[i] = (suff_hash_2[i-1] + (s[i]-'a'+1) * pow_p1[i]) % m2;
    }
}

void solve()
{
    string s, good_bad;
    cin >> s >> good_bad;
    int k, cnt = 0;
    cin >> k;
    n = s.length();
    bad_cnt.resize(n+1);
    pow_p.resize(n+1);
    pow_p1.resize(n+1);
    suff_hash_1.resize(n+1);
    suff_hash_2.resize(n+1);

    construct(s, good_bad);
    precomput_pow_p();
    comput_hash(s);

    ordered_set hs;
    for (int l = 1; l <= n; l++) {
        for (int i = 0; i < n - l; i++) {
            if (bad_cnt[i+l] - bad_cnt[i] > k) continue;
            int sub_has = (suff_hash_1[i+l] + m - suff_hash_1[i]) % m;
            sub_has = (sub_has * pow_p[n-i-1]) % m;

            int sub_has2 = (suff_hash_2[i+l] + m2 - suff_hash_2[i]) % m2;
            sub_has2 = (sub_has2 * pow_p1[n-i-1]) % m2;
            hs.insert({sub_has2, sub_has});  
        }
    }
    cout << (int)hs.size() << endl;
}



int32_t main()
{
    Faster;
    solve();
    return 0;
}
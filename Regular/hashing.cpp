#include<bits/stdc++.h>

using namespace std;
//#define int long long
#define endl "\n" 
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()

class HashedString {
    private:
    static const int M = 1e9+9;
    static const int B = 9973;

    // pow[i] stores B^i % M
    static vector < int > pow;

    // p_hash[i] is the hash of the first i characters of the given string
    vector < int > p_hash;

    public:
    HashedString(const string &s) : p_hash(s.size() + 1) {
        while (pow.size() < s.size()) 
            pow.push_back((pow.back() * B) % M);

        p_hash[0] = 0;
        for (int i = 0; i < s.size(); i++) {
            p_hash[i+1] = ((p_hash[i] * B) % M + s[i]) % M;
        }
    }

    int getHash(int s, int e) {
        int raw_val = (p_hash[e+1] - (p_hash[s] * pow[e - s + 1]));
        return (raw_val % M + M) % M;
    }
};
vector < int > HashedString::pow = {1};

void solve() {

}

int32_t main() {
    Faster;
    solve();   
    return 0;
}
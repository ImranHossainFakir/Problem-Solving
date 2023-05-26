// problme link -> https://codeforces.com/contest/230/problem/B
// amra ei problem ta moulik number er square die solve korte pari. Ex. 25 k jodi moulik number die factorization kori tahole 25 = 5 * 5. 
// moulik numbers er square gulo shobshomoye shudhu matro moulik number die divided hobe....tai er divisor shudhu matro 3 tai thakbe

#include "bits/stdc++.h"
     
using namespace std;

#define int long long
#define endl "\n"
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define all(x) (x).begin(), (x).end()

const int N = 1e6+9;
vector < bool > primes(N, true);

// createing sieve for finding a number is prime or not
void sive() {
    primes[1] = false;
    for (int i = 2; i*i < N; i++) {
        if (!primes[i]) continue;
        for (int j = i*i; j < N; j+=i) {
            primes[j] = false;
        }
    }
}

void solve() {
    int n; cin >> n;
    sive();
    while (n--) {
        int sqt, m; cin >> m;
        sqt = sqrt(m);
        if (sqt*sqt == m && primes[sqt]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}


int32_t main() {
    Faster;
    solve();
    return 0;
}

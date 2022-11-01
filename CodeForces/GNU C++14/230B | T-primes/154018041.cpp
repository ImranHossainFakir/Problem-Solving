#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+9;
 
bool primes[N];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    primes[1] = true;
    for (ll i = 2; i*i <= N; i++){
        for (ll j = i+i; j <= N; j+=i) {
            primes[j] = true;
        }
    }
 
    ll n; cin >> n;
    for (ll i = 1; i <= n; i++) {
        ll n;
        cin >> n;
        double x = sqrt(n+.0);
        if ((int)x == x && !primes[(int)x]) cout << "YES\n";
        else cout<<"NO\n";
    }
}
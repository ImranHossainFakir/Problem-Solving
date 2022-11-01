#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define mem(a, b) memset(a, b ,sizeof(a))
#define loop(b, e) for (int i = b; i < e; i++) 
#define lc (n * 2)
#define rc ((n * 2) + 1)
#define mid ((e+b) / 2)
 
const ll N = 2e5 + 9;
 
vector < ll > v[N];
bool vis[N];
vector< ll > dis(N);
ll ans = 0;
 
ll mx = 0;
ll color[N];
ll cnt[2];
 
void dfs(ll node, ll col) {
 if (vis[node] == 1) return;
 
 vis[node] = 1;
 color[node] = col;
 cnt[color[node]]++;
 
 for (auto u : v[node]) {
  dfs(u, col ^ 1);
 }
 
 return;
}
 
void solve(int cs) {
 
 ll n; cin >> n;
 
 for (int i = 0; i < n; i++) vis[i] = 0;
 
 for (int i = 1; i < n; i++) {
  
  ll x, y; cin >> x >> y;
  v[x].pb(y);
  v[y].pb(x);
 
 }
 
 cnt[0] = cnt[1] = 0;
 
 for (int i = 0; i < n; i++) {
  if (vis[i]) continue;
  dfs(i, 0);
  ans += max(cnt[0], cnt[1]);
  cnt[0] = cnt[1] = 0;
 }
 
 return;
}
 
void solve_cf() {
 ll p; cin >> p;
 if (p == 5) cout << 2 << " " << 4 << endl;
 else cout << 2 << " " << p/2 << endl;
 
 return;
}
 
ll gcd(ll a, ll b) {
 if (a == 0) return 0;
 return gcd(b % a, a);
}
 
int main() {
 IOS;
 
 ll t; cin >> t;
 
 while (t--) {
  solve_cf();
 }
 return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
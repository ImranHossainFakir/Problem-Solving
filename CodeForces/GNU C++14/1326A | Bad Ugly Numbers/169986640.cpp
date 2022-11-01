#include<bits/stdc++.h>
 
using namespace std;
 
//#define int long long
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define mem(a, b) memset(a, b ,sizeof(a))
#define loop(b, e) for (int i = b; i < e; i++) 
#define lc (n * 2)
#define rc ((n * 2) + 1)
#define mid ((e+b) / 2)
 
const int N = 2e5 + 9;
const int M = 2e4 + 9;
 
vector< int > v[N];
int vis[N];
int cnt[2];
int color[N];
int flag[M];
 
void dfs(int node, int col) {
 
 if (vis[node] == 1) return;
 vis[node] = 1;
 
 cnt[col]++;
 
 for (auto u : v[node]) {
  
  dfs(u, col ^ 1);
 }
}
 
void solve(int cs) {
 
 int n; cin >> n;
 mem(vis, 0);
 mem(flag, 0);
 
 
 for (int i = 0; i < n; i++) {
  int a, b; cin >> a >> b;
  v[a].pb(b);
  v[b].pb(a);
  flag[a] = 1;
  flag[b] = 1; 
 }
 
 cnt[0] = cnt[1] = 0;
 int ans = 0;
 
 for (int i = 1; i <= 20001; i++) {
  if (flag[i] == 0) continue;
  dfs(i, 0);
  int mx = max(cnt[0], cnt[1]);
  ans += mx;
  cnt[0] = cnt[1] = 0;
 }
 
 
 cout << "Case " << cs << ": " << ans << endl;
 
 for (auto& u : v) u.clear();
 
 return;
}
 
 
void solve() {
 int n; cin >> n;
 
 if (n == 1) {
  cout << -1 << endl;
  return;
 }
 
 if (n == 2) {
  cout << 23 << endl;
  return;
 }
 
 cout << 22;
 for (int i = 2; i < n; i++) cout << 3;
 cout << endl;
  
}
 
int32_t main() {
 IOS;
 
 int t; cin >> t;
 
 while (t--) {
  solve();
 }
 return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
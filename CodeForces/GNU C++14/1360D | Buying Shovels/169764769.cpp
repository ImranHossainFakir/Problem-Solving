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
 
vector< int > v[M];
vector< int > vis;
int weigth[N];
int flag[M];
int cnt[2];
int color[M];
 
void dfs(int node, int col) {
 
 if (vis[node] == 1) return;
 vis[node] = 1;
 color[node] = col;
 
 cnt[color[node]]++;
 
 for (auto u : v[node]) {
  
  dfs(u, col ^ 1);
 }
}
 
void solve(int cs) {
 
 int n; cin >> n;
 
 vis.resize(M);
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
 
 for (int i = 1; i < 20001; i++) {
  if (flag[i] == 0) continue;
  dfs(i, 0);
  ans += max(cnt[0], cnt[1]);
  cnt[0] = cnt[1] = 0;
 }
 
 
 cout << "Case " << cs << ": " << ans << endl;
 
 for (auto& u : v) u.clear();
 
 return;
}
 
 
void solve() {
 
 int n, k; cin >> n >> k;
 
 int srt = sqrt(n);
 
 int pack;
 
 for (int i = 1; i <= srt; i++) {
  if (n % i != 0) continue;
  if (n / i <= k) {
   pack = i;
   break;
  }
 
  if (i <= k) pack = n / i;
 }
 
 cout << pack << endl;
} 
 
 
int32_t main() {
 IOS;
 
 int t; cin >> t;
 
 while (t--) {
 
  solve();
 }
 return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
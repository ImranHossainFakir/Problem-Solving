#include<bits/stdc++.h>
 
using namespace std;
 
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define endl "\n"
 
int main() {
 IOS;
 
 ll t; cin >> t;
 
 while (t--) {
  int n, l, r; cin >> n >> l >> r;
 
  vector<int> v(n);
 
  for (int &e : v) cin >> e;
 
  sort(v.begin(), v.end());
 
  ll ans = 0;
 
  for (int i = 0, j = n-1, k = n-1; i < n; i++) {
   while (j > -1) {
    if (v[i]+v[j] <= r) break;
    j--;
   }
 
   while (k > -1) {
    if (l > v[i]+v[k]) break;
    k--;
   }
   ans += (j+1)-(k+1);
   if (l <= 2*v[i] && 2*v[i] <= r) ans--;
  }
  cout << (ans >> 1) << endl;
 }
}
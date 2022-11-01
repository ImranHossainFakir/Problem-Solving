#include<bits/stdc++.h>
 
using namespace std;
 
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
 
 
int main() {
 IOS;
 int t; cin >> t;
 
 outer : while (t--) {
  int k, n, m; cin >> k >> n >> m;
 
  int for_n[n], for_m[m];
 
  for (int i = 0; i < n; i++) cin >> for_n[i];
  for (int i = 0; i < m; i++) cin >> for_m[i];
  vector<ll> arr;
  
  for (int i = 0, j = 0; i < n || j < m;) {
   if (i < n && for_n[i] == 0) {
    arr.push_back(0);
    k++;
    i++;
   }
   else if (j < m && for_m[j] == 0) {
    arr.push_back(0);
    k++;
    j++;
   }
   else if (i < n && for_n[i] <= k) arr.push_back(for_n[i++]);
   else if (j < m && for_m[j] <= k) arr.push_back(for_m[j++]);
   else {
    cout << -1 << endl;
    goto outer;
   }
  }
 
  for (auto ele : arr) cout << ele << " ";
  cout << endl;
 }
}
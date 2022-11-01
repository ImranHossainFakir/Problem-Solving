#include<bits/stdc++.h>
 
using namespace std;
 
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
 
int main() {
 int t; cin >> t;
 
 while (t--) {
  int n, a; cin >> n >> a;
 
  vector<int> v(n);
 
  for (int& x: v) cin >> x;
 
  bool ans = false;
 
  if (n == 1 and v[0] == a) ans = true;
  else {
   sort(v.begin(), v.end());
   int i = 0;
   int j = 1;
 
   while (i < n and j < n) {
    if (v[i] + abs(a) == v[j]) {
     ans = true;
     break;
    }
    else if (v[i] + abs(a) < v[j]) ++i;
    else j++;
   }
  }
  cout << (ans ? "YES":"NO") << endl;
 }
}
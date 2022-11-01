#include<bits/stdc++.h>
 
using namespace std;
 
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
 
 
int main() {
 IOS;
 int t; cin >> t;
 
 while (t--) {
  int n; cin >> n;
  bool flag = false;
 
  vector<ll> arr(n);
 
  for (ll &e : arr) cin >> e;
  
  sort(arr.begin(), arr.end());
 
  for (int i = 1, j = n-1; i < j; ) {
   if (arr[i]+arr[0] < arr[n-1]) {
    flag = true;
    break;
   }
   arr[0] += arr[i++];
   arr[n-1] += arr[--j];
  }
 
  if (flag) cout << "YES" << endl;
  else cout << "NO" << endl;
 }
}
#include<bits/stdc++.h>
 
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
 
int main() {
 IOS;
 
 ll t;
 cin >> t;
 
 while (t--) {
  ll n; 
  cin >> n;
  
  if (n % 3 == 1) cout << 1;
  
  for (ll i = 0; i < n/3; i++) {
   cout << 21;
  }
  
  if (n % 3 == 2) cout << 2;
  cout << endl;
 }
 
 return 0;
}
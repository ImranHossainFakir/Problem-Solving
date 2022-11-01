#include<bits/stdc++.h>
 
using namespace std;
 
#define endl "\n"
#define ll long long 
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
int main() {
 IOS;
 ll t; cin >> t;
 while (t--) {
  ll a, b, c, d; cin >> a >> b >> c >> d;
  ll count = 0;
 
  if (a < b) count++;
  if (a < c) count++;
  if (a < d) count++;
 
  cout << count << endl;
 }
}
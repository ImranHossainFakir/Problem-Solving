#include<bits/stdc++.h>
 
using namespace std;
 
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
 
 
int main() {
 IOS;
 
 int t; cin >> t;
 
 while (t--) {
  ll n; cin >> n;
 
  if (n % 2 != 0 || n == 2) cout << -1 << endl;
  else if (n % 6 > 0) cout << n/6+1 << " " << n / 4 << endl;
  else cout << n / 6 << " " << n / 4 << endl;
 }
}
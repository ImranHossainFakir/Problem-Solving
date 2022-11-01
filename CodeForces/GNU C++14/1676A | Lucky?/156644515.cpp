#include<bits/stdc++.h>
 
using namespace std;
 
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define repl(i, n) for (int i = 0; i < n; i++)
 
int main() {
 IOS;
 
 int t; cin >> t;
 
 while (t--) {
  int n; cin >> n;
  int sum1 = 0;
  int sum2 = 0;
 
  sum1 += n / 100000;
  n = n%100000;
  sum1 += n / 10000;
  n = n % 10000;
  sum1 += n / 1000;
  n = n % 1000;
 
  sum2 = n / 100;
  n = n % 100;
  sum2 += n / 10;
  n = n % 10;
  sum2 += n;
 
  if (sum1 == sum2) cout << "YES" << endl;
  else cout << "NO" << endl;
 }
}
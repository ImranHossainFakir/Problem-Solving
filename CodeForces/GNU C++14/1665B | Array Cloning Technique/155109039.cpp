#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
 
const int N = 1e6;
 
int main() {
 IOS;
 
 int t;
 cin >> t;
 
 while (t--) {
  ll n, oper;
  cin >> n;
  ll a[n];
  oper = 0;
 
  for (int i = 0; i < n; i++) cin >> a[i];
 
  sort(a, a+n);
  int max_frequency = 0, frequency = 1;
 
  for (int i = 0; i < n-1; i++) {
   if (a[i] == a[i+1]) frequency++;
   else {
    max_frequency = max(frequency, max_frequency);
    frequency = 1;
   }
  }
  max_frequency = max(frequency, max_frequency);
 
  int need = n-max_frequency;
 
  while (max_frequency < n) {
   max_frequency *= 2;
   oper++;
  }
 
  cout << oper+need << endl;
 
 }
 return 0;
}
#include<bits/stdc++.h>
 
using namespace std;
 
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define repl(i, n) for (int i = 0; i < n; i++)
const int N = 100;
int main() {
 IOS;
 
 int t; cin >> t;
 
 while (t--) {
  int n, m; cin >> n >> m;
  string arr[n];
  int mn = INT_MAX;
 
  repl(i, n)
   cin >> arr[i];
   
  for (int i = 0; i < n-1; i++) {
   string s1 = arr[i];
   for (int j = i+1; j < n; j++) {
    string s2 = arr[j];
    int tem = 0;
    for (int k = 0; k < m; k++) tem += (abs(s1[k]-s2[k]));
    mn = min(tem, mn);
   }
  }
 
  cout << mn << endl;
 }
}
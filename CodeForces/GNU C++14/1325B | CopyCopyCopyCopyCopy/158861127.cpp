#include<bits/stdc++.h>
 
using namespace std;
 
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define endl "\n"
 
int main() {
 IOS;
 
 int t; cin >> t;
 
 while (t--) {
  int n; cin >> n;
 
  set<int> s;
 
  for (int i = 0; i < n; i++) {
   int tem; cin >> tem;
   s.insert(tem);
  }
 
  cout << s.size() << endl;
 }
}
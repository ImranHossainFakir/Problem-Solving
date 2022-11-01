#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define end "\n"
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
int main() {
 IOS;
 
 int t; cin >> t;
 
 while (t--) {
  int n, count; cin >> n;
  string str; cin >> str;
  count = 0;
  
  for (int j = n/2-1; j > -1; j--) {
   if (str[n/2] == str[j]) count++;
   else break;
  }
 
  if (n % 2) cout << count*2+1 << endl;
  else cout << count*2 << endl;
 }
}
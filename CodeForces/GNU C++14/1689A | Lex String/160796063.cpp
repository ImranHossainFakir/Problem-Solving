#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
struct Node {
 int zero, one, two;
};
 
int main() {
 
 IOS;
 
 int t; cin >> t;
 
 while (t--) {
  int n, m, k;
  cin >> n >> m >> k;
  string a, b, c; cin >> a >> b;
  sort(a.begin(), a.end(), greater<char>());
  sort(b.begin(), b.end(), greater<char>());
 
  int ak = 0, bk = 0;
 
  while (!a.empty() && !b.empty()) {
   char charA = a.back(), charB = b.back();
 
   if ((charA < charB && ak < k) || bk == k) {
    c.push_back(charA);
    ak++;
    bk = 0;
    a.pop_back();
   }
   else {
    c.push_back(charB);
    bk++;
    ak = 0;
    b.pop_back();
   }
  }
 
  cout << c << endl;
 }
}
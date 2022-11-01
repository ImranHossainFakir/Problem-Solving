#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
#define lc (n << 1)
#define rc ((n << 1) + 1)
#define mid ((e + b) >> 1)
const ll N = 2e5+9;
 
struct Node {
 int zero, one, two;
};
 
Node tree[3*N];
 
int main() {
 
 IOS;
 
 int t; cin >> t;
 
 back: while (t--) {
  int n; cin >> n;
 
  if (n == 1) {
      int a;
      cin>>a;
   cout << -1 << endl;
   goto back;
  }
 
  int arr[n];
  int ans[n];
 
  for (int i = 0; i < n; i++) {
   cin >> arr[i];
  }
 
  int next = 0, count = 1;
  for (int i = 0; i < n; i++) {
   if (next) {
    ans[i] = next;
    next = 0;
   }
   else if (arr[i] == count) {
    next = count;
    ans[i] = count + 1;
   }
   else {
    ans[i] = count;
   }
   count++;
  }
 
  if (ans[n-1] > n) {
   ans[n-1] = ans[n-2];
   ans[n-2] = n;
  }
 
  for (auto ele : ans) cout << ele << " ";
  cout << endl;
 }
}
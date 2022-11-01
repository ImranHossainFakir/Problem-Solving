#include<bits/stdc++.h>
 
using namespace std;
 
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
 
 
int main() {
 IOS;
 ll n, q, sum, count_2nd_op, last_val_2nd_op; cin >> n >> q;
 
 ll arr[2][n+1];
 sum = count_2nd_op = 0;
 
 for (int i = 1; i <= n; i++) {
  arr[0][i] = 1;
  cin >> arr[1][i];
  sum += arr[1][i];
 }
 
 while (q--) {
  int op; cin >> op;
 
  if (op == 1) {
   ll index, val; cin >> index >> val;
   if (count_2nd_op == 0) {
    sum += val;
    sum -= arr[1][index];
    arr[1][index] = val;
   }
   else if (arr[0][index] == count_2nd_op) {
    sum -= arr[1][index];
    sum += val;
    arr[1][index] = val;
   }
   else {
    arr[0][index] = count_2nd_op;
    sum -= last_val_2nd_op;
    sum += val;
    arr[1][index] = val;
   }
  }
  else {
   ll val; cin >> val;
   count_2nd_op--;
   sum = n*val;
   last_val_2nd_op = val;
  }
 
  cout << sum << endl;
 }
    
}
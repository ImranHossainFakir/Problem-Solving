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
  int n; cin >> n;
  int arr[n];
  int sum = 0;
 
  repl(i, n) {
   cin >> arr[i];
  }
 
  sort(arr, arr+n);
 
  repl(i, n-1)
   sum += (arr[i+1] - arr[0]);
  cout << sum << endl;
 }
}
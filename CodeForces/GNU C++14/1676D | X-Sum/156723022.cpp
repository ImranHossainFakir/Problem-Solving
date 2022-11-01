#include<bits/stdc++.h>
 
using namespace std;
 
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout(0);
#define repl(i, n) for (int i = 0; i < n; i++)
const int N = 2e5+1;
int main() {
 int t; cin >> t;
 
 while (t--) {
  int n, m; cin >> n >> m;
  int arr[n][m];
  int mx = INT_MIN;
 
  for (int i = 0; i < n; i++) {
   for (int j = 0; j < m; j++) {
    cin >> arr[i][j];
   }
  }
 
  for (int i = 0; i < n; i++) {
   for (int j = 0; j < m; j++) {
    int tem = arr[i][j];
 
    for (int k = i-1, l = j-1; k > -1 && l > -1; k--, l--) tem += arr[k][l];
    for (int k = i-1, l = j+1; k > -1 && l < m; k--, l++) tem += arr[k][l];
    for (int k = i+1, l = j-1; k < n && l > -1; k++, l--) tem += arr[k][l];
    for (int k = i+1, l = j+1; k < n && l < m; k++, l++) tem += arr[k][l];
    mx = max(mx, tem);
   }
  }
  cout << mx << endl; 
 }
 
 return 0;
}
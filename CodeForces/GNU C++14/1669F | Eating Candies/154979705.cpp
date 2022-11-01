#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 int t;
 cin >> t;
 
 while (t--) {
  int n, count,i;
  cin >> n;
  count = 0;
  int arr[n+1];
 
  for (i = 1; i <= n; i++) cin >> arr[i];
  int p1 = 0, p2 = 0, j = n;
  i = 1;
  while (i < j) {
   if (arr[i] == arr[j]) {
    i++;
    p1 = i-1;
    j--;
    p2 = n-j;
   }
   else if (arr[i] > arr[j]) {
    arr[j-1] += arr[j];
    j--;
   }
   else {
    arr[i+1] += arr[i];
    i++;
   }
 
   count = p1+p2;
  }
 
  cout << count << "\n";
 
 }
 
 return 0;
}
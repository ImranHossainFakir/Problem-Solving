#include<bits/stdc++.h>
 
using namespace std;
 
#define endl "\n"
#define ll long long 
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
 
int main() {
 IOS;
 int t; cin >> t;
 
 while (t--) {
 
  int n; cin >> n;
  int arr[n];
  
  for (int i = 0; i < n; i++) {
   cin >> arr[i];
  }
 
  sort(arr, arr+n);
 
  int even = 0;
  int odd = 0;
  int count = 1;
 
  for (int i = 1; i < n; i++) {
   if (arr[i] == arr[i-1]) {
    count++;
   }
   else {
    if (count % 2 == 0) even++;
    else odd++;
    count = 1;
   }
  }
  if (count > 0 && count % 2 == 0) even++;
  else if (count > 0 ) odd++;
 
  even = even - (even%2);
  
  cout << odd+even << endl;
 }
}
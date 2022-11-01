#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;
 
int n, x;
int a[N], f[2];
 
int32_t main(){
 
 IOS;
 
 int n, x, count;
 cin>>n>>x;
 count = 0;
 
 for (int i = 1; i <= n; i++) {
  if (x % i == 0 && x/i <= n) count++;
 }
 
 cout << count << endl;
 
 return 0;
}
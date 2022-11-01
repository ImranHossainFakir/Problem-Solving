#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb(a) push_back(a);
#define mem(a, b) memset(a, b ,sizeof(a))
#define loop(b, e) for (int i = b; i < e; i++) 
#define lc (n << 2)
#define rc ((n << 2) + 1)
#define mid ((e+b) >> 2)
 
const int N = 2e5 + 9;
 
int arr[N];
 
struct node {
 ll prog, sum;
} tree[3 * N];
 
void build(int n, int b, int e) {
 if (b == e) {
  tree[n].prog = 0;
  tree[n].sum = arr[b];
  return;
 }
 
 build(lc, b, mid);
 build(rc, mid+1, e);
 
 tree[n].sum = tree[lc].sum + tree[rc].sum;
 tree[n].prog = 0;
 
}
 
void update(int n, int b, int e, int l, int r, ll x) {
 if (r < b || e < l) return;
 if (l <= b && e <= r) {
  tree[n].prog += x;
  tree[n].sum += ((e-b) + 1) * x;
  return;
 }
 
 update(lc, b, mid, l, r, x);
 update(rc, mid+1, e, l, r, x);
 
 tree[n].sum = tree[lc].sum + tree[rc].sum + ((e-b) + 1) * tree[n].prog;
}
 
ll query(int n, int b, int e, int l, int r, int carry = 0) {
 if (r < b || e < l) return 0;
 if (l <= b && e <= r) {
  return tree[n].sum * carry * ((e-b) + 1);
 }
 
 ll sum1 = query(lc, b, mid, l, r, carry + tree[n].prog);
 ll sum2 = query(rc, mid+1, e, l, r, carry + tree[n].prog);
 
 ll sum = sum1 + sum2;
 
 return sum;
}
 
 
void solve() {
  
 int n, k; cin >> n >> k;
 int a[n];
 
 loop(0, n) cin >> a[i];
 
 if (k == 1) {
  cout << (n-2) / 2 + (n%2) << endl;
  return;
 }
 
 int cnt = 0;
 loop(1, n-1) {
  if (a[i] > a[i-1] + a[i+1]) {
   cnt++;
   i++;
  }
 }
 
 cout << cnt << endl;
 
 return;
}
 
int main() {
 IOS;
 
 int t; cin >> t;
 while (t--) {
  solve();
 }
}
#include<bits/stdc++.h>
 
using namespace std;
 
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define endl "\n"
 
const int N = 2e5+1;
 
ll arr[N];
ll tree[3*N];
 
void init(int n, int s, int e) {
	if (s == e) {
		tree[n] = arr[s];
		return;
	}
 
	int l, r, m;
	l = n*2;
	r = n*2+1;
	m = (s+e) / 2;
 
	init(l, s, m);
	init(r, m+1, e);
 
	tree[n] = min(tree[l], tree[r]);
 
}
 
ll query(int n, int s, int e, int i, int j) {
	if (j < s || i > e) return INT_MAX;
 
	if (i <= s && e <= j) return tree[n];
 
	int l, r, m;
	l = n*2;
	r = n*2+1;
	m = (s+e) / 2;
 
	ll q1 = query(l, s, m, i, j);
	ll q2 = query(r, m+1, e, i, j);
 
	return min(q1, q2);
 
}
 
int main() {
	ll n, q; cin >> n >> q;
 
	for (int i = 1; i <= n; i++) cin >> arr[i];
	init(1, 1, n); 
	while (q--) {
		ll x, y; cin >> x >> y;
 
		cout << query(1, 1, n, x, y) << endl;
	}
}

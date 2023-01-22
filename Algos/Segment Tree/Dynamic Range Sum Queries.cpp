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
 
	tree[n] = tree[l] + tree[r];
 
}
 
ll query(int n, int s, int e, int i, int j) {
	if (j < s || i > e) return 0;
 
	if (i <= s && e <= j) return tree[n];
 
	int l, r, m;
	l = n*2;
	r = n*2+1;
	m = (s+e) / 2;
 
	ll q1 = query(l, s, m, i, j);
	ll q2 = query(r, m+1, e, i, j);
 
	return q1+q2;
 
}
 
void update(int n, int s, int e, int i, int num) {
	if (i < s || e < i) return;
	if (s == i && e == i) {
		tree[n] = num;
		return;
	}
 
	int l, r, m;
	l = n*2;
	r = n*2+1;
	m = (s+e) / 2;
 
	update(l, s, m, i, num);
	update(r, m+1, e, i, num);
 
	tree[n] = tree[l] + tree[r];
}
 
int main() {
	ll n, q; cin >> n >> q;
 
	for (int i = 1; i <= n; i++) cin >> arr[i];
	init(1, 1, n); 
	while (q--) {
		ll v; cin >> v;
 
		if (v == 1) {
			ll k, u; cin >> k >> u;
			update(1, 1, n, k, u);
		}
		else {
			ll x, y; cin >> x >> y;
			cout << query(1, 1, n, x, y) << endl;
		}
	}
}

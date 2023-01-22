#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define end "\n"
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
const int N = 2e5+9;
int arr[1000][1000];
int tree[1001][2*N];
 
void init(int node, int s, int e, int row) {
	if (s == e) {
		tree[row][node] = arr[row][s];
		return;
	}
 
	int left, rigth, mid;
	left = node*2;
	rigth = node*2+1;
	mid = (s+e) / 2;
 
	init(left, s, mid, row);
	init(rigth, mid+1, e, row);
 
	tree[row][node] = tree[row][left] + tree[row][rigth];
 
}
 
int query(int node, int s, int e, int low, int high, int row) {
	if (high < s || e < low) return 0;
	if (low <= s && e <= high) {
		return tree[row][node];
	}
 
	int l, r, m;
	l = node*2;
	r = node*2+1;
	m = (s+e) / 2;
 
	int sum = query(l, s, m, low, high, row) + query(r, m+1, e, low, high, row);
 
	return sum;
}
 
int main() {
	IOS;
	int n, q; cin >> n >> q;
 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c; cin >> c;
			arr[i][j] = 46 - c;
		}
	}
 
	for (int i = 0; i < n; i++) {
		for (int j = n-1; j > 0; j--) {
			arr[j-1][i] += arr[j][i];
		}
	}
 
	for (int i = 0; i < n; i++) {
		init(1, 0, n-1, i);
	}
 
	while (q--) {
		int a, b, c, d; cin >> a >> b >> c >> d;
 
		int ans = query(1, 0, n-1, b-1, d-1, a-1) - query(1, 0, n-1, b-1, d-1, c);
 
		cout << ans / 4 << endl;
	}
 
}

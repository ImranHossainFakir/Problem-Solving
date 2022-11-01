#include<bits/stdc++.h>

using namespace std;

#define endl "\n"
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
const int N = 1e5+1;

int main() {
	IOS;

	int q; cin >> q;

	while (q--) {
		ll n; cin >> n;
		ll pos, neg;
		pos = 0;
		neg = 0;

		for (int i = 0; i < n; i++) {
			int tem; cin >> tem;
			if (tem < 0) neg++;
			else if (tem > 0) pos++;
		}

		// n = n*(n+1)/2
		ll pairs_by_positive = (pos-1)*pos / 2;
		ll pairs_by_negative = (neg-1)*neg / 2;

		cout << pairs_by_negative+pairs_by_positive << endl;
	}
}







		 
		

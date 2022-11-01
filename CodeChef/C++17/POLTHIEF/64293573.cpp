#include<bits/stdc++.h>

using namespace std;

#define endl "\n"
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
	IOS;

	int t; cin >> t;

	while (t--) {
		int x, y, time_need;
		cin >> x >> y;
		time_need = abs(x-y);
		cout << time_need << endl;
	}
}

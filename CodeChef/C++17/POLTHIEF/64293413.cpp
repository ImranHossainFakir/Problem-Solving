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
		time_need = 0;

		if (x > y) {
			while (x != y) {
				time_need++;
				x -= 2;
				y--;
			}
		}
		else {
			while (x != y) {
				time_need++;
				x += 2;
				y++;
			}
		}

		cout << time_need << endl;
	}
}

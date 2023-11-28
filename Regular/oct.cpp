#include <bits/stdc++.h>

using namespace std;
// #define int long long
#define endl "\n"
#define Faster                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define mem(a, b) memset(a, b, sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()

void solve()
{

  vector < int > arr;
  string str;
  while ((cin >> str) && str != "end")
  {
    arr.push_back(stoi(str));
  }
  
  int mx = INT_MIN;
  for (auto e : arr) cout << e << " ";
  for (auto e : arr) mx = max(mx, e);
  int mx1 = INT_MIN;
  for (auto e : arr) {
    if (e < mx) {
      mx1 = max(mx1, e);
    }
  }
  cout << "\nMax " << mx << "\n2nd Max " << mx1 << endl;
}

int32_t main()
{

  Faster;
  int t, cs = 1; cin >> t;
  while(t--) {
    cout << "Case " << cs++ << ": " << endl;
    solve();
  }
  return 0;
}
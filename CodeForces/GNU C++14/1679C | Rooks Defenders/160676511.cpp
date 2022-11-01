#include<bits/stdc++.h>
 
using namespace std;
 
#define endl "\n"
#define ll long long 
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lc (n * 2)
#define rc ((n * 2) + 1)
#define mid ((e + b) / 2)
 
vector<int> row;
vector<int> col;
vector<int> countRow;
vector<int> countCol;
 
 
 
void type1(int n, int b, int e, int index, vector<int> &vec) {
 if (b == index && e == index) {
  vec[n] = 1;
  return ;
 }
 if (!(b <= index && index <= e)) return;
 
 type1(lc, b, mid, index, vec);
 type1(rc, mid+1, e, index, vec);
 
 vec[n] = vec[lc] + vec[rc];
}
 
 
 
void type2(int n, int b, int e, int index, vector<int> &vec) {
 if (b == index && e == index) {
  vec[n] = 0;
  return;
 }
 if (!(b <= index && index <= e)) return;
 
 type2(lc, b, mid, index, vec);
 type2(rc, mid+1, e, index, vec);
 
 vec[n] = vec[lc] + vec[rc];
}
 
int type3(int n, int b, int e, int low, int high, vector<int> &vec) {
 if (high < b || e < low) return 0;
 if (low <= b && e <= high) return vec[n];
 
 int sum = type3(lc, b, mid, low, high, vec) + type3(rc, mid+1, e, low, high, vec);
 
 return sum;
}
 
int main() {
 IOS;
 int n, q; cin >> n >> q;
 row.resize(3*n);
 col.resize(3*n);
 countCol.resize(n+1);
 countRow.resize(n+1);
 
 
 while (q--) {
  int type; cin >> type;
  if (type == 1) {
   int x, y; cin >> x >> y;
   countRow[x]++;
   countCol[y]++;
   type1(1, 1, n, x, row);
   type1(1, 1, n, y, col); 
  }
  else if (type == 2) {
   int x, y; cin >> x >> y;
   countRow[x]--;
   if (countRow[x] == 0) {
    type2(1, 1, n, x, row);
   }
   countCol[y]--;
   if (countCol[y] == 0) {
    type2(1, 1, n, y, col);
   }
  }
  else {
   int a, b, c, d; cin >> a >> b >> c >> d;
   int row_wise = type3(1, 1, n, a, c, row);
   int col_wise = type3(1, 1, n, b, d, col);
 
   if (row_wise == c+1-a || col_wise == d+1-b) cout << "Yes";
   else cout << "No";
 
   cout << endl;
  }
 }
}
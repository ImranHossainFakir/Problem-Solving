#include<bits/stdc++.h>
 
using namespace std;
 
#define endl "\n"
#define ll long long 
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const ll N = 8;
 
string str[N];
 
ll find_2_attack(int index) {
 while (index < 8) {
  int count = 0;
  for (int j = 0; j < 8; j++) {
   if (str[index][j] == '#') count++;
   if (count == 2) return index;
  }
  index++;
 }
 return index;
}
 
int main() {
 IOS;
 ll t; cin >> t;
 while (t--) {
  for (int i = 0; i < 8; i++) {
   cin >> str[i];
  }
 
  ll row, col;
  row = find_2_attack(0);
 
  while (true) {
   int count = 0;
   col = 0;
   while (col < 8) {
    if (str[row][col] == '#') count++;
    col++;
   }
   if (count == 1) goto jump;
   row++;
  }
 
  jump:
 
  col = 0;
 
  while (true) {
   if (str[row][col] == '#') break;
   col++;
  }
 
  cout << row+1 << " " << col+1 << endl;
 }
}
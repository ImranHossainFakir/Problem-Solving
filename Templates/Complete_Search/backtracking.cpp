

/*

Problem link: 
Time Complexity: 

*/


#include<bits/stdc++.h>

using namespace std;
int cnt = 0, n;
const int N = 1e3;
vector < int > col(N), dig1(N), dig2(N);


void placeTheQueen(int y)
{
    if (y == n)
    {
        cnt++;
        return;
    }
    for (int x = 0; x < n; x++)
    {
        if (col[x] || dig1[x+y] || dig2[x-y+n-1])
            continue;
        col[x] = dig1[x+y] = dig2[x-y+n-1] = 1;
        placeTheQueen(y+1);
        col[x] = dig1[x+y] = dig2[x-y+n-1] = 0;
    }
}

int32_t main() {
    cin >> n;
    placeTheQueen(0);
    cout << cnt;
    return 0;
}
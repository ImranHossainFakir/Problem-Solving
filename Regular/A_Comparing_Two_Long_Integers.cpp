

/*

Problem link: https://codeforces.com/problemset/problem/616/A
Time Complexity: 

*/


#include<bits/stdc++.h>

using namespace std;
//#define int long long
#define endl "\n" 
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()


string removeLeadingZeros(string str)
{
    // Find the index of the first non-zero character
    size_t index = str.find_first_not_of('0');

    // Extract substring from the first non-zero character to the end
    string withoutLeadingZeros = (index != string::npos) ? str.substr(index) : "0";

    return withoutLeadingZeros;
}

char compare(string a, string b)
{
    // comparing count of the digits of the numbers
    // if ((int)a.size() > (int)b.size())
    //     return '>';
    // else if ((int)a.size() < (int)b.size())
    //     return '<';


    // // if count of the digits are same then compare corresponding chars
    // int i, j;
    // for (i = 0, j = 0; i < (int)a.size() && j < (int)b.size(); i++, j++)
    // {
    //     if (a[i] > b[j])
    //         return '>';
    //     else if (a[i] < b[j])
    //         return '<';
    // }
    if (a > b)
        return '>';
    else if (a < b)
        return '<';

    return '=';
}

void solve()
{
    string a, b; cin >> a >> b;
    a = removeLeadingZeros(a);
    b = removeLeadingZeros(b);
    // what_is(a);
    // what_is(b);
    
    cout << compare(a, b) << endl;
}
int32_t main() {
    Faster;
    
    solve();
    return 0;
}
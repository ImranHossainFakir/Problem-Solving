#include <bits/stdc++.h>

using namespace std;
// #define int long long
#define endl "\n"
#define Faster                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define mem(a, b) memset(a, b, sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()

// Finding the left most A.
int findA(string &str) 
{
    int len = str.length();
    for (int i = 0; i < len; i++)
        if (str[i] == 'A')
            return i;

    return -1;
}

// Finding the rightmost B.
int findB(string &str) 
{
    int len = str.length();
    for (int i = len-1; i >= 0; i--)
        if (str[i] == 'B')
            return i;
    return -1;
}

int solve()
{
    int n, cntA = 0, ans = 0, B, A;
    cin >> n;
    string str;
    cin >> str;
    A = findA(str);
    B = findB(str);
    
    if (A == -1 || B == -1)
        return ans;

    
    for (int i = A; i <= B; i++)
    {
        // Counting Consecutive A
        if (str[i] == 'A')
            cntA++;
        else if (str[i] == 'B' && cntA)
        {
            ans += cntA;
            cntA = 0;
            while (++i <= B && str[i] == 'B')
                ans++;
            // If i is less then B then it is confirm that
            // in the right side of i have/has some A and B.
            if (i < B)
                ans++;
            i--;
        }
    }
    return ans;
}

int32_t main()
{
    Faster;
    int t;
    cin >> t;
    while (t--)
        cout << solve() << endl;
    return 0;
}
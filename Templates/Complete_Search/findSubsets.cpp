

/*

Problem link: 
Time Complexity: 

*/


#include<bits/stdc++.h>

using namespace std;

const int N = 1e3, n = 3;

vector < int > subsets;

// using recursion
void method1(int k)
{
    if (k == n)
    {
        int len = (int)subsets.size();
        cerr << "{";
        if (len == 0)
        {
            cerr << "}";
            return;
        }
        for (int i = len-1; ;)
        {
            cerr << subsets[i];
            subsets.pop_back();
            if (--i < 0)
                break;
            cerr << ", ";
        }
        cerr << "}";
    }
    else 
    {

        method1(k+1);
        // before k included
        subsets.push_back(k);
        // after k included
        method1(k+1);
        subsets.pop_back();
    }
}

void method2()
{
    for (int b = 0; b < (1<<n); b++)
    {
        vector <int> subset;
        for (int i = 0; i < n; i++)
        {
            if (b & (1<<i)) subset.push_back(i);
        }
    }
}

int32_t main() {
    
    method1(0);
    return 0;
}
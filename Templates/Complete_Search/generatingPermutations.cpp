


#include<bits/stdc++.h>

using namespace std;

int const N = 1e3;
vector < int > permutation;
vector < bool > chosen(N, false);
int n = 2;

void method1()
{
    if (permutation.size() == n)
    {
        for (int i = 0; i < n; i++)
            cout << permutation[i] << " ";
        cout << endl;
    }
    else 
    {
        for (int i = 0; i < n; i++)
        {
            if (chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i);
            method1();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

void method2()
{
    for (int i = 0; i < n; i++)
        permutation.push_back(i);
    int cnt = 1;
    do
    {
        // process permutations
        for (int i = 0; i < n; i++)
            cout << permutation[i] << " ";
        cout << endl;
    } while (next_permutation(permutation.begin(), permutation.end()));
    
}

int32_t main() {
    
    method1();
    return 0;
}
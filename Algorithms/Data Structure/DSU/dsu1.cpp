

#include<bits/stdc++.h>

using namespace std;

const int N = 1e3;

vector < int > parent(N);

// To create a new set consisting of the new element 'v'
void makeSet(int v)
{
    parent[v] = v;
}

// To find representative of the set to which 'v' belongs.
int findSet(int v)
{
    if (v == parent[v])
        return v;
    return findSet(parent[v]);
}

// To merge the sepecified sets to which 'a' and 'b' belong.
void unionSets(int a, int b)
{
    a = findSet(a);
    b = findSet(b);

    if (a != b)
        parent[b] = a;
}

int32_t main() {
    

    return 0;
}
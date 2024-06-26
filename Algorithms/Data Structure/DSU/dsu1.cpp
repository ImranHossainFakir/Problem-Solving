

#include<bits/stdc++.h>

using namespace std;

const int N = 1e3;

vector < int > parent(N), sz(N);

// To create a new set consisting of the new element 'v'
void makeSet(int v)
{
    parent[v] = v;
    sz[v] = 1;
}

// To find representative of the set to which 'v' belongs.
int findSet(int v)
{
    if (v == parent[v])
        return v;
    // by compressing path we directly connecting vertexes to the root.
    return parent[v] = findSet(parent[v]);
}

// To merge the sepecified sets to which 'a' and 'b' belong.
void unionSets(int a, int b)
{
    a = findSet(a);
    b = findSet(b);

    if (a != b)
    {
        if (sz[a] < sz[b])
            swap(a, b);
        
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int32_t main() {
    

    return 0;
}
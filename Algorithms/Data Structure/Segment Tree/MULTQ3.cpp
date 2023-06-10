// Problem link -> https://www.spoj.com/problems/MULTQ3/
// ei problem ta lazy die solve kora hoice. update query te lazy hishbe amra shob shomoi current node er child node 2 tar lazy k update kore propage kore nicher dike update ta pathie diccih. 

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

const int N = 1e5 + 9;

struct Node
{
    int zero, one, two, lazy;
};

vector<Node> tree(N << 2);

void swap1(int node)
{
    swap(tree[node].zero, tree[node].one);
    swap(tree[node].zero, tree[node].two);
}

void swap2(int node)
{
    swap(tree[node].zero, tree[node].two);
    swap(tree[node].zero, tree[node].one);
}

// passing the lazy to the corresponding  childs and update the node.
void propagate(int node, int l, int r)
{
    int l_child = node << 1, r_child = (node << 1) + 1;
    if (l != r)
    {
        tree[l_child].lazy = (tree[l_child].lazy + tree[node].lazy) % 3;
        tree[r_child].lazy = (tree[r_child].lazy + tree[node].lazy) % 3;
    }
    if (tree[node].lazy == 1)
        swap1(node);
    else
        swap2(node);
    tree[node].lazy = 0;
}

void build(int node, int l, int r)
{
    if (l == r)
    {
        tree[node].zero = 1;
        tree[node].one = tree[node].two = tree[node].lazy = 0;
        return;
    }

    int l_child, r_child, m;
    l_child = node * 2;
    r_child = node * 2 + 1;
    m = (l + r) / 2;
    build(l_child, l, m);
    build(r_child, m + 1, r);

    tree[node].zero = tree[l_child].zero + tree[r_child].zero;
    tree[node].one = tree[l_child].one + tree[r_child].one;
    tree[node].two = tree[l_child].two + tree[r_child].two;
    tree[node].lazy = 0;
}

void update(int node, int l, int r, int x, int y)
{
    int l_child = node * 2, r_child = node * 2 + 1, m = (l + r) >> 1;

    // jodi node er lazy thake tahole node er child der kace lazy ta pass kore diccih abong lazy wise update kore diccih.
    if (tree[node].lazy)
        propagate(node, l, r);
    if (y < l || r < x)
        return;
    if (x <= l && r <= y)
    {
        // kangkhito node pawar por node er child gulote update ta pouche diccih lazy k update kore.
        if (l != r)
        {
            tree[l_child].lazy = (1 + tree[l_child].lazy) % 3;
            tree[r_child].lazy = (1 + tree[r_child].lazy) % 3;
        }
        swap1(node);
        return;
    }
    update(l_child, l, m, x, y);
    update(r_child, m + 1, r, x, y);

    tree[node].zero = tree[l_child].zero + tree[r_child].zero;
    tree[node].one = tree[l_child].one + tree[r_child].one;
    tree[node].two = tree[l_child].two + tree[r_child].two;
}

int query(int node, int l, int r, int x, int y)
{
    int l_child = node * 2, r_child = node * 2 + 1, m = (l + r) >> 1;

    // jodi node er lazy thake tahole node er child der kace lazy ta pass kore diccih abong lazy wise update kore diccih.
    if (tree[node].lazy)
        propagate(node, l, r);
    if (y < l || r < x)
        return 0;
    if (x <= l && r <= y)
        return tree[node].zero;

    return query(l_child, l, m, x, y) + query(r_child, m + 1, r, x, y);
}

void solve()
{
    int n, q;
    cin >> n >> q;
    build(1, 1, n);

    while (q--)
    {
        int type, x, y;
        cin >> type >> x >> y;
        x++;
        y++;
        if (type == 0)
        {
            update(1, 1, n, x, y);
        }
        else
            cout << query(1, 1, n, x, y) << endl;
    }
    
}

int32_t main()
{
    Faster;

    solve();
    
    return 0;
}

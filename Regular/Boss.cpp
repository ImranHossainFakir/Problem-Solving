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
const int N = 1e3;
int y_age, state = 1;

vector<int> parents[N];
vector<int> childs[N];
vector<int> vis_state(N);
vector<int> ages(N);

void query(int node)
{
    vis_state[node] = state;

    for (auto par : parents[node])
    {
        if (vis_state[par] == state) // if visiting state is equla state then node is visited
            continue;
        // before entering the parent node check age
        y_age = min(ages[par], y_age);
        // entering the parent node
        query(par);
        // exiting the parent node
    }
    // exiting the node
}
void copy_childs(int a, int b, vector<int>& c1, vector<int>& c2, vector<int>& par1, vector<int>& par2) {
    for (auto child : c1) {
        parents[child].erase(remove(all(parents[child]), a), parents[child].end());
        if (child == b) childs[b].push_back(a);
        else {
            childs[b].push_back(child);
            parents[child].push_back(b);
        }
    }
    for (auto child : c2) {
        parents[child].erase(remove(all(parents[child]), b),parents[child].end());
        if (child == a) childs[a].push_back(b);
        else {
            childs[a].push_back(child);
            parents[child].push_back(a);
        }
    }
}

void copy_parents(int a, int b, vector<int>& p1, vector<int>& p2, vector<int>& chi1, vector<int>& chi2) {

    for (auto parent : p1) {
        childs[parent].erase(remove(all(childs[parent]), a), childs[parent].end());
        if (parent == b) parents[b].push_back(a);
        else {
            parents[b].push_back(parent);
            childs[parent].push_back(b);
        }
    }
    for (auto parent : p2) {
        childs[parent].erase(remove(all(childs[parent]), b), childs[parent].end());
        if (parent == a) parents[a].push_back(b);
        else {
            parents[a].push_back(parent);
            childs[parent].push_back(a);
        }
    }
}

void update(int e_1, int e_2) {
    vector < int > c1, c2, p1, p2;
    // copying and removing childs and parents
    c1 = childs[e_1];
    childs[e_1].clear();
    c2 = childs[e_2];
    childs[e_2].clear();
    p1 = parents[e_1];
    parents[e_1].clear();
    p2 = parents[e_2];
    parents[e_2].clear();

    copy_childs(e_1, e_2, c1, c2, parents[e_1], parents[e_2]);
    copy_parents(e_1, e_2, p1, p2, childs[e_1], childs[e_2]);
    // cerr << "============" << endl;
    // cerr << e_1 << ": ";
    // for (auto e : parents[e_1]) cerr << e <<" ";
    // cerr << endl;
    // cerr << e_2 << ": ";
    // for (auto e : parents[e_2]) cerr << e <<" ";
    // cerr << endl;
    // cerr << "============" << endl;
    // cerr << e_1 << ": ";
    // for (auto e : childs[e_1]) cerr << e <<" ";
    // cerr << endl;
    // cerr << e_2 << ": ";
    // for (auto e : childs[e_2]) cerr << e <<" ";
    // cerr << endl;

}

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++)
        cin >> ages[i];
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        childs[x].push_back(y);
        parents[y].push_back(x);
        
    }

    while (q--)
    {
        char type;
        cin >> type;
        if (type == 'P')
        {
            int epl_no;
            cin >> epl_no;
            y_age = 101;
            query(epl_no);
            if (y_age == 101)
                cout << "*" << endl;
            else
                cout << y_age << endl;
            state++;
        }
        else {
            int e_1, e_2; cin >> e_1 >> e_2;
            update(e_1, e_2);
        }
    }
}

    
int32_t main()
{
    Faster;
    solve();
    // int three = 3, six = 6;
    // parents[three] = {1};
    // childs[three] = {5, 6};
    // parents[six] = {3, 4};
    // childs[six] = {7};

    // cout << "===============before swaping==============" << endl;
    // cout << three << "\n";
    // for (auto e : parents[three]) cout << e <<" ";
    // cout << endl;
    // for (auto e : childs[three]) cout << e <<" ";

    // cout << endl << six << endl;
    // for (auto e : parents[six]) cout << e << " "; 
    // cout << endl;
    // for (auto e : childs[six]) cout << e << " "; 

    // update(three, six);

    // cout << "=================after swaping==============" << endl;
    // cout << "three" << "\n";
    // for (auto e : parents[three]) cout << e <<" ";
    // cout << endl;
    // for (auto e : childs[three]) cout << e <<" ";

    // cout << endl << "six" << endl;
    // for (auto e : parents[six]) cout << e << " "; 
    // cout << endl;
    // for (auto e : childs[six]) cout << e << " "; 
    return 0;
}
#include<bits/stdc++.h>

using namespace std;
//#define int long long
#define endl "\n" 
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()

int n;

struct compareval
{
    bool operator()(const int& a, const int& b)
    {
        return a > b;
    }
};

vector < int > bfs(vector < int > adj[], vector < int >& indegree) {
    vector < int > solution;
    priority_queue<int, vector<int>, compareval> q;
    for (int i = 1; i <= n; i++) {
        if (!indegree[i]) q.push(i);
    }

    while (!q.empty())
    {
        int u = q.top(); q.pop();
        solution.push_back(u);

        for (auto v : adj[u]) 
        {
            indegree[v]--;
            if (!indegree[v]) q.push(v);
        }
    }
    return solution;
}

void solve() {
    int cs = 1;
    while (true) {
        cin >> n;
        vector < int > adj[n+1];
        map<string , int> mp;
        vector< string > arr(n+1);
        vector < int > indegree(n+1);
        for (int i = 0; i < n; i++) {
            cin >> arr[i+1];
            mp[arr[i+1]] = i+1;
        }
        int m; cin >> m;
        for (int i = 0; i < m; i++) {
            string s1, s2; cin >> s1 >> s2;
            adj[mp[s1]].push_back(mp[s2]);
            indegree[mp[s2]]++;
        }

        vector < int > solution = bfs(adj, indegree);
        cout << "Case #" << cs << ": Dilbert should drink beverages in this order:"; 
        for (int i = 0; i < solution.size(); i++) {
            cout << " " << arr[solution[i]];
        }
        cs++;
        cout << "." << endl << endl;
        if (cin.eof()) 
            break;
    }
}

int32_t main() {
    Faster;
    solve();   
    return 0;
}
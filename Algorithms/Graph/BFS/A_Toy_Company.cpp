// problem link -> https://lightoj.com/problem/a-toy-company
// To solve this problem we used BFS to find the answer. 
// We picked a word/string and figured out the possible states for it. 
// Checked all the possible words/strings that will have forbidden string or not.
// Compared all possible words with the Finish word/string are they same or not. if same then answer is found.

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

set<string> forbiddens;
map<string, bool> vis;
string start, finish;

int bfs()
{
    queue<string> q;
    q.push(start);
    int d = 0;

    while (!q.empty())
    {
        d++;
        int sz = q.size();
        while (sz--)
        {
            string cur = q.front();
            q.pop();
            for (int i = 0; i < 3; i++)
            {
                string t1 = cur, t2 = cur;
                t1[i] = (char)(cur[i] - 'a' + 1) % 26 + 'a';
                t2[i] = (char)(cur[i] - 'a' - 1 + 26) % 26 + 'a';
                if (forbiddens.find(t1) == forbiddens.end() && !vis[t1]) 
                {
                        vis[t1] = true;
                        q.push(t1);
                }
                if (forbiddens.find(t2) == forbiddens.end() && !vis[t2]) 
                {
                    vis[t2] = true;
                    q.push(t2);
                }
                if (t1 == finish || t2 == finish)
                    return d;

            }
        }
    }
    return d;
}

void solve()
{
    cin >> start >> finish;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string a, b, c;
        cin >> a >> b >> c;
        for (int j = 0; j < a.size(); j++)
        {
            for (int k = 0; k < b.size(); k++)
            {
                for (int l = 0; l < c.size(); l++)
                {
                    string cur = "";
                    cur += a[j];
                    cur += b[k];
                    cur += c[l];
                    forbiddens.insert(cur);
                }
            }
        }
    }
    vis[start] = true;
    vis[finish] = true;
    if (forbiddens.find(start) != forbiddens.end() || forbiddens.find(finish) != forbiddens.end())
    {
        cout << -1 << endl;
    }
    else if (start == finish)
        cout << 0 << endl;
    else
        cout << bfs() << endl;

    vis.clear();
    forbiddens.clear();
}

int32_t main()
{
    Faster;
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}

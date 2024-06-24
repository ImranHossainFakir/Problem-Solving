#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define nl "\n"
#define FASTER                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

void solve() 
{
    int n, sum = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 0)
            sum++;
    }

    if (sum > 2)
    {
        cout << "YES" << endl;
        return;
    }
    vector<int> pos(1001), neg(1001);
    vector<int> posArr, negArr;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0 && neg[-1 * arr[i]] < 2)
        {
            neg[-1 * arr[i]]++;
            negArr.push_back(-1 * arr[i]);
        }
        else if (arr[i] >= 0 && pos[arr[i]] < 2)
        {
            pos[arr[i]]++;
            posArr.push_back(arr[i]);
        }
    }

    for (int i = 0; i < (int)negArr.size(); i++)
    {
        int tem = negArr[i];
        for (int j = i + 1; j < (int)negArr.size(); j++)
        {
            if (pos[tem + negArr[j]])
            {
                cout << "YES" << endl;
                return;
            }
        }
    }

    for (int i = 0; i < (int)posArr.size(); i++)
    {
        int tem = posArr[i];
        for (int j = i + 1; j < (int)posArr.size(); j++)
        {
            if (neg[tem + posArr[j]])
            {
                cout << "YES" << endl;
                return;
            }
        }
    }

    cout << "NO" << endl;
}
int main()
{
    solve();
}


//  #include <bits/stdc++.h>
//  using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     int a[n];
//     map<int, int> mp;
//     vector<int> vec;
//     vec.push_back(1);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//         mp[a[i]]++;
//     }
//     for(auto [val, cnt]: mp) {
//        if(cnt >= 2) {
//            vec.push_back(val);
//            vec.push_back(val);
//        }
//        if(cnt == 1)
//            vec.push_back(val);
    
//     }
//     int sz = vec.size();
//     bool flag = 0;
//     for (int i = 0; i < sz; i++)
//     {
//         for (int j = i + 1; j < sz; j++) {
//             int x = (vec[i] + vec[j]) * -1;
//             if (mp[x])
//              flag = 1;
//         }
//     }
//     if(flag || mp[0] > 2)
//         cout << "YES\n";
//     else cout << "NO\n";
// }
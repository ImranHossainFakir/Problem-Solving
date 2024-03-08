#include "bits/stdc++.h"

using namespace std;

#define int long long
#define endl "\n"
#define Faster                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define mem(a, b) memset(a, b, sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define all(x) (x).begin(), (x).end()

vector<int> multiply(const vector<int> &a, const vector<int> &b)
{
    int m = a.size();
    int n = b.size();
    vector<int> result(m + n, 0);

    for (int i = m - 1; i >= 0; --i)
    {
        for (int j = n - 1; j >= 0; --j)
        {
            int product = a[i] * b[j] + result[i + j + 1];
            result[i + j + 1] = product % 10;
            result[i + j] += product / 10;
        }
    }

    // Remove leading zeros
    while (!result.empty() && result.front() == 0)
    {
        result.erase(result.begin());
    }

    return result;
}

int32_t main()
{
    Faster;

    int t;
    cin >> t;
    while (t--)
    {
        string num1, num2;
        int pos;
        cin >> num1 >> num2 >> pos;
        vector<int> a, b;
        for (int i = 0; i < num1.size(); i++)
            a.push_back(num1[i] - '0');

        for (int i = 0; i < num2.size(); i++)
            b.push_back(num2[i] - '0');
        // while (num1)
        // {
        //     a.push_back(num1 % 10);
        //     num1 /= 10;
        // }

        // while (num2)
        // {
        //     b.push_back(num2 % 10);
        //     num2 /= 10;
        // }

        // reverse(all(a));
        // reverse(all(b));

        vector<int> result = multiply(a, b);

        // for (int e : result)
        //     cout << e;
        // cout << endl;
        cout << (result[pos - 1] % 2 ? "ODD" : "EVEN") << endl;
    }

    return 0;
}
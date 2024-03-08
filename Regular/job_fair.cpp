#include "bits/stdc++.h"

using namespace std;

// #define int long long
#define endl "\n"
#define Faster                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define mem(a, b) memset(a, b, sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define all(x) (x).begin(), (x).end()
#define what_is(x) cerr << #x << " is " << x << endl;

struct recrd
{
    string name, phone, date, time, dept, rev_a, rev_t;
    int dept_level;
    recrd(){}
    recrd(string name, string phone, string dept, string date, string time, string rev_a, string rev_t, int dept_level) : name(name), phone(phone), dept(dept), date(date), time(time), rev_a(rev_a), rev_t(rev_t), dept_level(dept_level) {}
};

vector<recrd> lst;
vector < recrd > uniq_lst;
map < string, int > deprt;

// sorting the given list based on time
bool based_on_time(recrd &a, recrd &b)
{
    return a.rev_t < b.rev_t;
}

// to sort the unique list based on level, date, phone
bool based_ave(recrd &a, recrd &b)
{
    if (a.dept_level != b.dept_level)
        return a.dept_level > b.dept_level;
    else if (a.rev_a != b.rev_a)
        return a.rev_a < b.rev_a;
    
    return a.phone < b.phone;
}

void create_dept_level()
{
    deprt["CSE"] = 5;
    deprt["EEE"] = 4;
    deprt["ME"] = 3;
    deprt["IPE"] = 2;
    deprt["CE"] = 1;
}

string string_reverse(string str, char splt)
{
    vector<std::string> splitParts;

    // Use std::istringstream to split the string
    istringstream iss(str);
    string part;

    while (getline(iss, part, splt)) {
        splitParts.push_back(part);
    }

    return splitParts[2] + splt + splitParts[1] + splt + splitParts[0];
}

void solve()
{
    string name;

    // assigning dept's levels
    create_dept_level();

    while (cin >> name)
    {
        string p, d, a, t, rev_a, rev_t;
        cin >> p >> d >> a >> t;
        rev_a = string_reverse(a, '-');
        rev_t = string_reverse(t, ':');
        
        lst.push_back(recrd(name, p, d, a, t, rev_a, rev_t, deprt[d]));
    }

    // sorting based on time
    sort(all(lst), based_on_time);


    map<string, recrd> mp;

    // storing last recored data on the given list
    for (recrd e : lst)
    {
        mp[e.phone] = recrd(e.name, e.phone, e.dept, e.date, e.time, e.rev_a, e.rev_t, deprt[e.dept]);

        // mp.emplace(e.phone, recrd(e.name, e.phone, e.dept, e.date, e.time));
    }
    
    // to transfer unique records to a vector for sorting.
    for (auto entry : mp)
    {
        recrd v = entry.second;
        uniq_lst.push_back(recrd(v.name, v.phone, v.dept, v.date, v.time, v.rev_a, v.rev_t, deprt[v.dept]));
    }

    // To sort based on deprtment's level, data and phone
    sort(all(uniq_lst), based_ave);

    // cout << "============= after sort ==========" << endl;
    for (recrd e : uniq_lst)
    {
        cout << e.name << " " << e.phone << " "
             << e.dept << " " << e.date << " " << e.time << endl;
    }
}

int32_t main()
{
    Faster;
    solve();
    return 0;
}
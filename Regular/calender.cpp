

/*

Problem link:
Time Complexity:

*/

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

// storing days of specific months.
vector<int> months_days{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
// storing days of week
map<string, int> week;

struct Date
{
    int day, month, year;
    string w;
    Date(int day, int month, int year, string w) : day(day), month(month), year(year), w(w) {}
};

Date take_date()
{
    string st1, st2;
    cin >> st1 >> st2;

    // Create a stringstream from the input string
    std::stringstream ss(st1);

    // Vector to store the split parts
    std::vector<std::string> result;

    // Temporary string to hold each part
    std::string part;
    while (std::getline(ss, part, '/'))
    {
        result.push_back(part);
    }

    return Date(stoi(result[0]), stoi(result[1]), stoi(result[2]), st2);
}

void make_weeks()
{
    // For simplicity each day holds a index.
    week["Sun"] = 0;
    week["Mon"] = 1;
    week["Tue"] = 2;
    week["Wed"] = 3;
    week["Thu"] = 4;
    week["Fri"] = 5;
    week["Sat"] = 6;
}

void print_calender(vector<int> &calender)
{
    cout << "|---------------------------|" << endl;
    cout << "|Sun|Mon|Tue|Wed|Thu|Fri|Sat|";

    for (int i = 0; i < 35; i++)
    {
        if (i % 7 == 0)
        {
            cout << endl << "|---------------------------|" << endl;
            cout << "|";
        }
        if (calender[i] < 10 && calender[i])
            cout << "  " << calender[i] << "|";
        else if (calender[i] > 9)
            cout << " " << calender[i] << "|";
        else
            cout << " - |";
    }
    cout << endl << "|---------------------------|" << endl;
    cout << endl;
}

// finding the day in week of 1 
int starting_day(int a, int b)
{
    while (true)
    {
        if (a == 1)
            return b;
        a--;
        b--;

        if (b < 0)
            b = 6;
    }
}
void solve()
{
    Date date = take_date();

    // updating february month based on leap year.
    if ((date.year % 100 == 0 && date.year % 400 == 0) || (date.year % 100 && date.year % 4 == 0))
        months_days[2] = 29;
    else
        months_days[2] = 28;

    // For simplicity each day holds a index.
    make_weeks();

    int start_day = starting_day(date.day, week[date.w]);

    // storing date of the month.
    vector<int> calender(5 * 7, 0);
    
    // creating calending 
    for (int i = start_day, cnt = 0; cnt < months_days[date.month]; i++, cnt++)
        calender[i % 35] = cnt+1 % months_days[date.month];

    print_calender(calender);
}

int32_t main()
{
    Faster;

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
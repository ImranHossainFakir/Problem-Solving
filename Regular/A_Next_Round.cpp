#include<bits/stdc++.h>

using namespace std;
#define int long long
#define endl "\n" 
#define on true
#define Faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mem(a, b) memset(a, b ,sizeof(a))
#define len(a) sizeof(a) / sizeof(int)
#define what_is(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()


void reverse(stack < char >& st) {
    if (st.empty()) return;
    char c = st.top();
    st.pop();
    reverse(st);
    cout << c;
}


string receivedText(string S) {
    // WRITE DOWN YOUR CODE HERE
    bool num_locked = on, h = 0;
    stack < char > end;
    stack < string > home;
    string str;


    for (auto c : S) {
        if (c == '#') num_locked ^= 1;
        else if (c == '<' || c == '>') {
            if (h) home.push(str);
            if (c == '<') h = 1;
            else h = 0;
            str = "";
        }
        else if (c == '*') {
            if (str.size()) str.pop_back();
            if (!end.empty() && !h) end.pop();
        }
        else if (isdigit(c)) {
            if (num_locked) {
                str += c;
                if (!h) end.push(c);
            }
        }
        else  {
            str += c;
            if (!h) end.push(c);
        }
    }

    if (str.size()) { // jodi last character ta '<' or '>' nah hoi tahole str home e add hocche nah tai
                      // home e str add korchi jodi str e kichu thake....
        if (h) home.push(str);
    }
    
    while (!home.empty()) {
        string tem = home.top();
        home.pop();
        cout << tem;
    }

    stack < char > v;
    while (!end.empty())
    {
        v.push(end.top());
        end.pop();
    }
    
    while (!v.empty())
    {
        cout << v.top();
        v.pop();
    }

    return "";
}


int32_t main() {
    Faster;
    string s;
    getline(cin, s);
    receivedText(s);
    
    return 0;
}
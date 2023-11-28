#include <bits/stdc++.h>

using namespace std;

typedef int in;
#define int long long

in main()
{
    int n;
    string s;
    cin >> s;
    n = s.size();
    stack<string> q;
    bool b1 = 0,num=0;
    string s1 = "",ans = "";
    for(int i = 0 ; i < n ; i ++) {
        if(s[i] == '>'){
            q.push(s1);
            s1="";
            b1 = 0;
            continue;
        }
        if(s[i] == '<'){
            q.push(s1);
            b1 = 1;
            s1="";
            continue;
        }
        if(s[i]=='*')
        {
            if(b1){
                if(s1.size())
                    s1.pop_back();
            }
            else{
                if(ans.size())
                    ans.pop_back();
            }
            continue;
        }
        if(s[i]=='#')
        {
            num^=1;
            continue;
        }
        if(b1){
            if(isdigit(s[i]) && num)
                continue;
            s1.push_back(s[i]);
        }
        else{
            if(isdigit(s[i]) && num)
                continue;
            ans.push_back(s[i]);
        }
    }
    if(s1.size()){
        q.push(s1);
    }
    while(q.size()){
        cout << q.top();
        q.pop();
    }
    cout << ans << endl;
    return 0;
}
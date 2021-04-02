#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll dr, st;
string s;
stack <char> stk;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("paranteze2.in");
    ofstream cout("paranteze2.out");

    cin >> s;
    for (ll i = 0; i < s.length(); i++){
        if (stk.empty()){
            stk.push(s[i]);
            continue;
        }

        if (s[i] == ')' && stk.top() != s[i])
            stk.pop();
        else
            stk.push(s[i]);
    }

    while(!stk.empty()){
        if (stk.top() == ')')
            dr++;
        else
            st++;
        stk.pop();
    }

    cout << st / 2 + dr / 2 + (st % 2) * 2;

    return 0;
}

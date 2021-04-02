#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll n, m;
string s;
deque <char> stk;
char ans[1000005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("trompeta.in");
    ofstream cout("trompeta.out");

    cin >> n >> m >> s;
    for (ll i = 0; i < n; i++){
        if (stk.empty()){
            stk.push_back(s[i]);
            ans[1] = s[i];
        }
        while(!stk.empty() && m - stk.size() < n - i && stk.back() < s[i])
            stk.pop_back();

        if (stk.size() != m){
            stk.push_back(s[i]);
            ans[stk.size()] = s[i];
        }
    }
    cout << ans + 1;

    return 0;
}

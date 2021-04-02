#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll n, t, b[200005];
bool check[200005];
deque <ll> stk;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n;
    for (ll i = 0; i < n; i++){
        cin >> t;
        stk.push_back(t);
    }
    for (ll i = 0; i < n; i++)
        cin >> b[i];

    for(ll i = 0; i < n; i++){
        ll nr = 0;
        if (check[b[i]] || stk.empty()){
            cout << nr << " ";
            continue;
        }
        while(!stk.empty() && stk.front() != b[i]){
            nr++;
            check[stk.front()]++;
            stk.pop_front();
        }
        nr++;
        check[stk.front()]++;
        stk.pop_front();
        cout << nr << " ";
    }


    return 0;
}

#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll n, k, num;
stack <ll> stk;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("nrpits.in");
    ofstream cout("nrpits.out");

    num = 0;
    cin >> n;
    while(n--){
        cin >> k;
        if (stk.empty())
            stk.push(k);
        else{
            while(stk.top() <= k && !stk.empty()){
                stk.pop();
                if (!stk.empty())
                    num++;
                else
                    break;
            }
            stk.push(k);
        }
    }

    cout << num;

    return 0;
}

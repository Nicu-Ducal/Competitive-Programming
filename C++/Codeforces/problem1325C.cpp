#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

const int maxN = 1e5+5;
ll n, ans[maxN], a, b;
vector <ll> tree[maxN];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n;
    for (ll i = 0; i <= n; i++)
        ans[i] = -1;
    for(ll i = 0; i < n - 1; i++){
        cin >> a >> b;
        tree[a].pb(i);
        tree[b].pb(i);
    }
    ll temp = 0;
    for (ll i = 1; i <= n; i++){
        if (tree[i].size() >= 3){
            for (auto &it: tree[i]){
                ans[it] = temp;
                temp++;
            }
            break;
        }
    }
    for (ll i = 0; i < n - 1; i++){
        if (ans[i] != -1)
            cout << ans[i] << '\n';
        else{
            cout << temp << '\n';
            temp++;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define pll pair <ll, ll>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll n, m, k, a, b;
vector < pll > timp1, timp2, good;

bool cmpLast(pll &x1, pll &x2){
    return x2.se > x1.se;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("licenta.in");
    ofstream cout("licenta.out");

    cin >> k >> n;
    for (ll i = 0; i < n; i++){
        cin >> a >> b;
        timp1.pb({a, b});
    }
    cin >> m;
    for (ll i = 0; i < m; i++){
        cin >> a >> b;
        timp2.pb({a, b});
    }

    sort(all(timp1), cmpLast);
    sort(all(timp2), cmpLast);

    ll i = 0, j = 0;
    while (i < n && j < m){
        int a = max(timp1[i].fi, timp2[j].fi);
        int b = min(timp1[i].se, timp2[j].se);
        if (b - a >= k){
            good.pb({a, b});
            break;
        }
        if (timp1[i].se < timp2[j].se)
            i++;
        else if (timp1[i].se > timp2[j].se)
            j++;
        else{
            i++;
            j++;
        }
    }

    for (auto &it : good){
        if (it.se - it.fi >= k){
            cout << it.fi << ' ' << it.fi + k;
            return 0;
        }
    }
    cout << "-1";

    return 0;
}

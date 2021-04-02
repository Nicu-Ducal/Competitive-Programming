#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

bool cmp(pair<ll,ll> x1, pair<ll,ll> x2){
    if (x1.fi == x2.fi)
        return x2.se < x1.se;
    return x1.fi < x2.fi;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    ll s, n, a, b;
    cin >> s >> n;
    pair <ll, ll> arr[n];
    for (ll i = 0; i < n; i++){
        cin >> a >> b;
        arr[i] = {a, b};
    }

    sort(arr, arr + n, cmp);

    bool ok = 1;
    for (ll i = 0; i < n; i++){
        if (s > arr[i].fi)
            s += arr[i].se;
        else{
            ok = 0;
            break;
        }
    }
    if (ok) cout << "YES";
    else cout << "NO";

    return 0;
}

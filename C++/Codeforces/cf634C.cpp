#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define len length()
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll t, n, a, b, c;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> t;
    while(t--){
        cin >> n;
        set<ll> s;
        ll v[n + 1];
        for(ll i = 0; i <= n; i++)
            v[i] = 0;
        for (ll i = 0; i < n; i++){
            cin >> a;
            v[a]++;
            s.insert(a);
        }

        if (n == 1){
            cout << 0 << '\n';
            continue;
        }
        else if (n == 2){
            cout << 1 << "\n";
            continue;
        }

        ll maxdiff = s.size(), maxsame = 1;
        for (auto &it : s)
            if (v[it] > 1)
                maxsame = max(maxsame, v[it]);

        if (maxsame >= maxdiff + 1)
            cout << maxdiff << "\n";
        else
            cout << min(maxdiff - 1, maxsame) << "\n";
        s.clear();
    }

    return 0;
}


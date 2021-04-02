#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll t, n, k;
map <ll, ll> fr;
map <int, int> put;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> t;
    while (t--){
        cin >> n >> k;
        ll a[n], v[n], idzero = 0;
        for(ll i = 0; i < n; i++){
            cin >> a[i];
            fr[a[i]]++;
            v[i] = 0;
        }

        bool ok = 1;
        for (auto &it : fr){                //Check
            if (it.fi != 0 && it.se > 1){
                cout << "NO\n";
                ok = 0;
                break;
            }
        }
        if (!ok){
            fr.clear();
            continue;
        }
        ok = 1;

        if (fr.find(0) != fr.end()){
            idzero = fr[0];
            if (fr[0] == n){
                cout << "YES\n";
                fr.clear();
                continue;
            }
        }

        bool one = 0;
        sort(a, a + n);
        if (a[idzero] == 1){
            one = 1;
            put[0]++;
        }

        for (ll i = ((one == 0) ? idzero : idzero + 1); i < n; i++){
            bool stop = 0;
            ll init = a[i];
            if (a[i] % k != 0 && (a[i] - 1) % k == 0 && one == 0){
                a[i] -= 1;
                one = 1;
                put[0] = 1;
            }
            ll ptemp = 0;
            if (a[i] % k == 0){
                while (!stop && ok){
                    while (a[i] % k == 0){
                        a[i] /= k;
                        ptemp++;
                    }
                    put[ptemp]++;
                    if (put[ptemp] > 1){
                        ok = 0;
                        break;
                    }
                    if ((a[i] - 1) % k == 0 && init != a[i])
                        a[i]--;
                    else{
                        ok = 0;
                        break;
                    }
                    if (a[i] == 0){
                        stop = 1;
                        continue;
                    }
                }
            }
            else{
                ok = 0;
                break;
            }
            if (!ok)
                break;
        }
        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";

        put.clear();
        fr.clear();
    }
    return 0;
}

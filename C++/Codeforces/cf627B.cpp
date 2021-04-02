#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll t, n, cnt[10000];
bool ok = 0;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> t;
    while(t--){
        ok = 0;
        for (ll i = 0; i < 5005; i++)
            cnt[i] = 0;
        cin >> n;
        ll a[n];
        for (ll i = 0; i < n; i++){
            cin >> a[i];
        }

        cnt[a[0]]++;
        for(ll i = 1; i < n; i++){
            if(a[i] == a[i - 1])
                continue;
            else
                if (cnt[a[i]]){
                    ok = 1;
                    break;
                }
                else
                    cnt[a[i]]++;
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";

    }

    return 0;
}

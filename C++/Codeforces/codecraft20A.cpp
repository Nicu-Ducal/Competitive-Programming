#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    ll t, n, m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        ll a[n], sum = 0;
        for (ll i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
        }
        if (sum <= m)
            cout << sum << endl;
        else
            cout << m << endl;
    }

    return 0;
}

#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll t, n, even, odd;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> t;
    while(t--){
        cin >> n;
        ll a[n];
        odd = 0; even = 0;
        for (ll i = 0; i < n; i++){
            cin >> a[i];
            if (a[i] & 1)
                odd++;
            else
                even++;
        }
        if (odd == n || even == n)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}

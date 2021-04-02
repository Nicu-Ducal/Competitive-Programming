#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        ll p1, p2;
        for (ll i = n - 2; ~i; i--){
            if (k < n - 1 - i){
                p1 = i;
                p2 = n - 1 - i;
                break;
            }
            k -= n - 1 - i;
        }
        for (ll i = 0; i < n; i++){
            if (i == p1 or i == p2)
                cout << "b";
            else
                cout << "a";
        }
        cout << "\n";
    }

    return 0;
}

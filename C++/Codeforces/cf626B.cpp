#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    ll n, m, k;
    cin >> n >> m >> k;
    ll a[n], b[m], c[n][m];
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < m; i++)
        cin >> b[i];

    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m; j++){
            c[i][j] = a[i] * b[j];

        }

    for (ll i = 0; i < n; i++){
        for (ll j = 0; j < m; j++)
            cout << c[i][j] << " ";
        cout << "\n";
    }

    return 0;
}

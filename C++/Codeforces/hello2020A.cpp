#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll n, m, p, q;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n >> m;

    string s[n], t[m];
    for (ll i = 0; i < n; i++)
        cin >> s[i];
    for (ll i = 0; i < m; i++)
        cin >> t[i];

    cin >> p;
    for (ll i = 0; i < p; i++)
    {
        cin >> q;
        cout << s[(q - 1) % n] << t[(q - 1) % m] << "\n";
    }

    return 0;
}

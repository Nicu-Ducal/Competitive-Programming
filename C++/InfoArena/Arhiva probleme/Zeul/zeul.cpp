#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll n, m, a, b, tab[100010], ans, pp, pm;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("zeul.in");
    ofstream cout("zeul.out");

    cin >> n >> m;
    for (ll i = 0; i < m; i++){
        cin >> a >> b;
        tab[a]++;
        tab[b]--;
    }

    for (ll i = 1; i <= n; i++)
        if (tab[i] > 0)
            ans += tab[i];

    cout << ans << "\n";

    while (ans--){
        while (!(tab[pp] > 0) && pp <= n)
            pp++;
        while (!(tab[pm] < 0) && pm <= n)
            pm++;
        cout << pm << " " << pp << "\n";
        tab[pp]--;
        tab[pm]++;
    }

    return 0;
}

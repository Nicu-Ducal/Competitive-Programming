#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll n, ans = 0, phi[1000005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("fractii.in");
    ofstream cout("fractii.out");

    cin >> n;

    for (ll i = 1; i <= n; i++)
        phi[i] = i - 1;
    for (ll i = 2; i <= n; i++)
    {
        for (ll j = 2 * i; j <= n; j += i)
            phi[j] -= phi[i];
        ans += phi[i];
    }
    cout << 1 + ans * 2;

    return 0;
}

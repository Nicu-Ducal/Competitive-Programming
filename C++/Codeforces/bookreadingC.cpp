#include <bits/stdc++.h>
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

int main(){
ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

ll q;
cin >> q;
while (q--)
{
    ll n, m;
    cin >> n >> m;
    ll p = n / m;
    ll tab[10];
    ll sum = 0;
    for (int i = 0; i <= 9; i++)
    {
        tab[i] = (i * m) % 10;
        sum += tab[i];
    }
    ll ans = (p / 10) * sum;
    for (int i = 0; i <= p%10; i++)
        ans += tab[i];
    cout << ans << "\n";
}

return 0;
}

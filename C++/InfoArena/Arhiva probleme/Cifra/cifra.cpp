#include <bits/stdc++.h>
typedef unsigned int ui;
typedef long long ll;
using namespace std;

ll t, n, ultsum[101], ans;
char str[105];

ll ultcif(ll n)
{
    ll exp = (n % 4 != 0) ? (n % 4) : 4;
    n = n % 10;
    ll ans = 1;
    for (ll i = 1; i <= exp; i++)
        ans *= n;
    return ans % 10;
}

void calcul()
{
    ultsum[0] = 0;
    for (ll i = 1; i < 100; i++)
        ultsum[i] = (ultsum[i - 1] + ultcif(i)) % 10;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("cifra.in");
    ofstream cout("cifra.out");

    calcul();
    cin >> t;
    while(t--)
    {
        cin >> str;
        ll len = strlen(str);
        ans = str[len - 1] - '0';
        if (len > 1)
            ans += (str[len - 2] - '0') * 10;
        cout << ultsum[ans] << "\n";
    }

    return 0;
}

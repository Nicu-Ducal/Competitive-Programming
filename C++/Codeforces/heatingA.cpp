#include <bits/stdc++.h>
typedef unsigned int ui;
typedef long long ll;
using namespace std;

ll n, c, sum;

int main(){
ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

cin >> n;
while (n--)
{
    cin >> c >> sum;

    if (c == 1)
    {
        cout << sum * sum << "\n";
        continue;
    }
    if (c >= sum)
    {
        cout << sum << "\n";
        continue;
    }

    ll div = sum / c;
    ll mod = sum % c;
    ll suma = 0;
    /*for (ll i = 1; i <= c; i++)
    {
        if (i <= mod)
        {
            suma += (div + 1) * (div + 1);
            continue;
        }
        suma += div * div;
    }*/
    suma = mod * (div + 1) * (div + 1) + (c - mod) * div * div;
    cout << suma << "\n";
}

return 0;
}

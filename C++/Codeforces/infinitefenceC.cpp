#include <bits/stdc++.h>
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll t, r, b, k;

ll gcd(ll a, ll b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(){
ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

cin >> t;
while (t--)
{
    cin >> r >> b >> k;
    if (r == b)
    {
        cout << "OBEY\n";
        continue;
    }
    ll gc = gcd (r, b);
    ll lcm = r / gc * b;
    char a[2 * lcm];
    a[0] = 'r' ? r > b : 'b';
    bool rebel = 0;
    ll chk = 1;
    ll last = 0;
    for (ll i = 1; i < 2 * lcm; i++) //i < 2 * lcm
    {
        if (i % r == 0 || i % b == 0)
        {
            if (i % r == 0) a[i] = 'r';
            else a[i] = 'b';
            if (i == lcm) a[i] = a[0];
            if (a[last] == a[i])
            {
                chk++;
                if (chk == k)
                {
                    cout << "REBEL\n";
                    rebel = 1;
                    break;
                }
            }
            else chk = 1;
            last = i;
        }
    }
    if (rebel == 0) cout << "OBEY\n";
}

return 0;
}

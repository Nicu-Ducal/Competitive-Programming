#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll t, a, b;

int main(){
ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        if (a == b)
        {
            cout << "0\n";
            continue;
        }
        ll n = 1;
        bool flag = 1;
        while (flag)
        {
            ll sum = (n * (n + 1)) / 2;
            ll k2 = a + b + sum;
            if (k2 % 2 == 0)
            {
                ll k = k2 / 2;
                if (k >= b && k >= a)
                {
                    cout << n << "\n";
                    flag = 0;
                }
                else
                   n++;
            }
            else
                n++;
        }
    }

return 0;
}

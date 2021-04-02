#include<bits/stdc++.h>
#define fi first
#define se second
typedef long long ll;
using namespace std;

ll t, n;

ll twoCounter(ll x)
{
    ll num = 0;
    while (x % 2 == 0)
    {
        num ++ ;
        x /= 2;
    }
    return num;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        ll a[n];
        bool p[n];
        ll odd = 0;
        ll even = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] % 2 == 1)
                odd++;
            else
                even++;
        }

        if (odd == n)
        {
            cout << 0 << "\n";
            continue;
        }

        sort(a, a + n, greater<int>());
        //for (int i = 0; i < n; i++) cout << a[i] << " ";
        //cout << "\n";
        ll req = 0;
        ll i = 0;

        while (even)
        {
            bool p = a[i] % 2;
            bool flag = 1;
            if (!p)
            {
                ll counter = 1;
                ll curr = a[i];
                ll next = a[i + 1];
                while (curr == next)
                {
                    counter++;
                    next = a[i + counter];
                }
                //cout << "counter: " << counter << "\n";
                for (ll j = i; j < i + counter; j++)
                {
                    if (flag) req++;
                    flag = 0;
                    a[j] /= 2;
                }
                //for (int i = 0; i < n; i++) cout << a[i] << " ";
                if (a[i] % 2 == 1) even -= counter;
                sort(a, a + n, greater<int>());
                //for (int h = 0; h < n; h++) cout << a[h] << " ";
                //cout << "\n";
            }
            else i++;
        }

        cout << req << "\n";
    }


    return 0;
}

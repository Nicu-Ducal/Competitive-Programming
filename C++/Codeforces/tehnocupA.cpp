#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll t,n;

ll beautiful(ll n)
{
    ll num = 9; ll p = 10; ll all = 0;
    if (n >= 1 && n <= 9) return n;
    all += num;

    vector <ll> t;
    t.push_back(1);

    for (int r = 0; r <= 10; r++){
        ll d = n / p;
        t.push_back(p);
        if (d >= 10)
        {
            p *= 10;
            all += num;
            continue;
        }
        else
        {
            ll chk = 0;
            for (int i = 0; i < t.size(); i++)
            {
                chk += d * t[i];
            }
                if (n >= chk)
                {
                    all += d;
                    return all;
                }
                else
                {
                    all += (d-1);
                    return all;
                }
            }
        }

    }





int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << beautiful(n) << "\n";
    }


    return 0;
}

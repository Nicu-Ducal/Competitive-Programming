#include <bits/stdc++.h>
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll numc = 0;

ll mooreMajority(ll n, ll a[])
{
    ll s = 0;
    ll c = -1;
    for (ll i = 0; i < n; i++)
    {
        if (s == 0)
        {
            s = 1;
            c = a[i];
        }
        else if (a[i] == c) s++;
        else s--;
    }
    if (s == 0) return -1;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] == c) numc++;
    }
    if (numc > n / 2) return c;
    return -1;
}

int main(){
ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
ifstream cin("elmaj.in");
ofstream cout("elmaj.out");

ll n;
cin >> n;
ll a[n];
for (ll i = 0; i < n; i++)
{
    cin >> a[i];
}
ll res = mooreMajority(n, a);
cout << res << " " << numc;


return 0;
}

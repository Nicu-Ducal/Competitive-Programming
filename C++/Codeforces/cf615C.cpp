#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll save, isave, putsave;
bool isprime[100005];
vector <ll> prime;

bool ciur()
{
    for (ll i = 0; i < 100005; i++)
        isprime[i] = 1;
    isprime[0] = isprime[1] = 0;
    for (ll i = 2; i < 100005; i++)
    {
        if (isprime[i])
        {
            prime.pb(i);
            for (ll j = 2 * i; j < 100005; j += i)
                isprime[j] = 0;
        }
    }
}

bool prim(ll n)
{
    ll i = isave;
    if (n == 2 || n == 3 || n == 7 || n == 5)
        return 1;
    while (1)
    {
        if (prime[i] >= sqrt(n) + 1)
            return 1;
        if (n % prime[i] == 0)
        {
            save = prime[i];
            putsave = 0;
            while (n % save == 0)
            {
                n /= save;
                putsave++;
            }
            isave = i + 1;
            return 0;
        }
        else
            i++;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ciur();
    ll t,n,a,b,c;

    cin >> t;
    while (t--)
    {
        cin >> n;
        ll num[3];
        bool ok = 1;
        isave = 0;
        save = 0;
        ll init = n;
        for (int x = 0; x < 2; x++)
        {

            if (prim(n))
            {
                cout << "NO\n";
                ok = 0;
                break;
            }
            else
            {
                num[x] = save;
                if(putsave >= 3 && x == 0)
                {
                    num[x + 1] = save * save;
                    break;
                }
                n /= save;
            }
        }
        if (ok)
        {
            num[2] = init / (num[0] * num[1]);
            if (num[2] == num[0] || num[2] == num[1] || num[2] == 1)
            {
                ok = 0;
                cout << "NO\n";
            }
        }
        if (ok)
        {
            cout << "YES\n" << num[0] << " " << num[1] << " " << num[2] << "\n";
        }

    }

    return 0;
}

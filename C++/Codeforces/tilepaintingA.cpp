#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll n;

bool ifprim(ll n)
{
    if (n == 2) return 1;
    for (int i = 2; i < sqrt(n) + 1; i++)
    {
        if (n % i == 0) return 0;
    }
    return 1;
}

ll primput(ll n)
{
    ll p;
    for (int i = 2; i < sqrt(n) + 1; i++)
    {
        if (ifprim(i) && (n % i == 0))
        {
            while (n % i == 0)
                n /= i;
            p = i;
            break;
        }
    }
    if (n == 1) return p;
    else return 0;
}

int main(){
ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n;

    if (n == 1)
    {
        cout << 1;
        return 0;
    }

    if (ifprim(n))
    {
        cout << n;
        return 0;
    }

    else if (primput(n) > 0)
    {
        cout << primput(n);
        return 0;
    }
    else
    {
        cout << 1;
    }

return 0;
}

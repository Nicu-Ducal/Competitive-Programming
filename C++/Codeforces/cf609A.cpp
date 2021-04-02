#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll a, b, n;

bool ifprim(ll n)
{
    for (int i = 2; i < sqrt(n) + 1; i++)
    {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n;

    a = n + 1;
    b = a + n;
    while (1)
    {
        if (ifprim(a) == 0 && ifprim(b) == 0)
        {
            cout << b << " " << a;
            break;
        }
        else
        {
            a++;
            b = n + a;
        }
    }

    return 0;
}

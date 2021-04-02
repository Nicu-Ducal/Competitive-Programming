#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll q, n;

int returner(ll n)
{
    if (n == 2) return 2;
    if (n % 2 == 1) return 1;
    return 0;
}

int main()
{
    cin >> q;
    while (q--)
    {
        cin >> n;
        cout << returner(n) << "\n";
    }
    return 0;
}

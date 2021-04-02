#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll t, n;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> t;
    while(t--)
    {
        cin >> n;
        ll a[n], sum, prod, change;
        sum = change = 0;
        prod = 1;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 0)
            {
                change++;
                a[i]++;
            }
            sum += a[i];
            prod *= a[i];
        }

        if (sum != 0)
            cout << change << '\n';
        else
        {
            bool minone = 1;
            for (ll i = 0; i < n; i++)
                if (a[i] != -1)
                {
                    change++;
                    cout << change << "\n";
                    minone = 0;
                    break;
                }
            if (minone)
            {
                cout << change + 2 << '\n';
            }
        }
    }

    return 0;
}

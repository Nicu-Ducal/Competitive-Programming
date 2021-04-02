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
        while (t--)
        {
            cin >> n;
            ll a[2 * n], cnt [2 * n];
            map <int, int> m;
            for (ll i = 0; i < 2 * n; i++)
            {
                cin >> a[i];
                if (a[i] == 2)
                    a[i] = -1;

            }
        }
    return 0;
}

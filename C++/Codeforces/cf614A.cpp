#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    ll t, n, s, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> s >> k;
        ll a[k];
        for (int i = 0; i < k; i++)
        {
            cin >> a[i];
            a[i] = abs(a[i] - s);
        }
        sort(a, a + k);

        ll b[k];
        for (int i = 0; i < k; i++)
            b[i] = 0;
        for (int i = 0; i < k; i++)
        {
            b[a[i]]++;
        }
        if (b[0] == 0)
        {
            cout << 0 << '\n';
            continue;
        }
        bool found = 0;
        for (int i = 1; i < min(s, a[k - 1]); i++)
            if (b[i] == 0 || b[i] == 1)
            {
                 cout << i << "\n";
                 found = 1;
                 break;
            }
        if (!found)
            for (int i = min(s, a[k - 1]); i <= a[k - 1]; i++)
                if (b[i] == 0)
                {
                    cout << i << "\n";
                    found = 1;
                    break;
                }
        if (!found)
            cout << a[k - 1] + 1 << "\n";
    }
    return 0;
}

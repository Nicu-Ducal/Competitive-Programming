#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    ll t, n, m;
    string s;

    cin >> t;
    while(t--)
    {
        cin >> n >> m >> s;
        ll p[m], mist[n], alf[26], num[n];
        for (ll i = 0; i < n; i++)
        {
             mist[i] = 0;
             num[i] = 1;
        }

        for (ll i = 0; i < m; i++)
        {
            cin >> p[i];
            p[i]--;
            mist[p[i]]++;
        }
        sort(p, p + m);

        for (ll i = 0; i < 26; i++)
            alf[i] = 0;

        for (ll i = n - 2; i >= 0; i--)
        {
            if (mist[i])
                num[i] = num[i + 1] + mist[i];
            else
                num[i] = num[i + 1];
        }

        for (ll i = 0; i < n; i++)
            alf[s[i] - 'a'] += num[i];

        for (ll i = 0; i < 26; i++)
            cout << alf[i] << " ";
        cout << "\n";
    }

    return 0;
}

#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    ll t, n;
    char c;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll odd = 0;
        vector <char> str;
        for (ll i = 0; i < n; i++)
        {
            cin >> c;
            if ((c - '0') % 2 == 1)
            {
                odd++;
                str.pb(c);
            }
        }
        if (odd % 2 == 0 && odd != 0)
            for (auto it: str)
                cout << it;
        else if (odd == 1 || odd == 0)
            cout << "-1";
        else
            for (ll i = 0; i < str.size() - 1; i++)
                cout << str[i];
        cout << "\n";
    }

    return 0;
}

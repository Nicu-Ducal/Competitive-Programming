#include <bits/stdc++.h>
#define pb push_back
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll n;
string s;
vector <ll> pos;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n >> s;

    ll wh = 0;
    ll bl = 0;
    ll counter = 0;
    vector <ll> change;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'B')
            bl++;
        if (s[i] == 'W')
            wh++;
    }

    if (bl == 0 || wh == 0)
    {
        cout << 0;
        return 0;
    }

    else if (bl % 2 == 1 && wh % 2 == 1)
    {
        cout << -1;
        return 0;
    }
    else
    {
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i] != 'W')
            {
                s[i] = 'W';
                if (s[i + 1] == 'B') s[i + 1] = 'W';
                else s[i + 1] = 'B';
                counter++;
                change.pb(i + 1);
            }
        }
        if (s[s.length() - 1] != 'W')
        {
            for (int i = 0; i < s.length() - 1; i += 2)
            {
                counter++;
                change.pb(i+1);
            }
        }
        cout << counter << "\n";
        for (int i = 0; i < change.size(); i++)
        {
            cout << change[i] << " ";
        }
    }


return 0;
}

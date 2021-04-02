#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll n, sx, sy;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    ll a, b;
    cin >> n >> sx >> sy;
    vector < pair <ll, ll> > v;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        v.pb({a, b});
    }

    vector < pair <ll, ll> > sh;
    sh.pb({sx - 1, sy});
    sh.pb({sx + 1, sy});
    sh.pb({sx, sy + 1});
    sh.pb({sx, sy - 1});

    ll st[4] = {0, 0, 0, 0};

    for (int i = 0; i < 4; i++)
    {
        ll shx = sh[i].fi;
        ll shy = sh[i].se;
        for (int j = 0; j < n; j++)
        {
            if ( (abs(sx - v[j].fi) + abs(sy - v[j].se) ) == ( abs(v[j].fi - shx) + abs(v[j].se - shy) + abs(shy - sy) + abs(shx - sx) ) )
               st[i]++;
        }
    }
    ll stmax = max(max(st[0], st[1]), max(st[2], st[3]));
    for (int i = 0; i < 4; i++)
    {
        if (st[i] == stmax)
        {
            cout << stmax << "\n" << sh[i].fi << " " << sh[i].se;
            break;
        }
    }
    return 0;
}

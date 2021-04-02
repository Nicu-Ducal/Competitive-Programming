#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("reactivi.in");
    ofstream cout("reactivi.out");

    ll n;
    cin >> n;

    pair <ll, ll> t[n];
    for (ll i = 0; i < n; i++)
        cin >> t[i].fi >> t[i].se;

    sort(t, t + n);
    ll frig = 1;
    ll temp = t[0].se;


    for (ll i = 1; i < n; i++)
    {
        if (t[i].fi <= temp)
            temp = min(temp, t[i].se);
        else
        {
            frig++;
            temp = t[i].se;
        }
    }

    cout << frig;

    return 0;
}

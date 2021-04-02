#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll n, s, num;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n;
    vector <ll> v[n];

    num = 0;
    ll temp = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> s;
        for (ll k = 0; k < s; k++)
        {   cin >> temp;
            v[i].pb(temp);
        }
    }






    return 0;
}

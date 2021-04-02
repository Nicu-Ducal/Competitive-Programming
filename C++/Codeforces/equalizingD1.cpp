#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ll n, k;
    cin >> n >> k;
    ll a[n];
    ll frec[200005];
    ll maxf = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        frec[a[i]]++;
        if (frec[a[i]] > maxf)
            maxf = frec[a[i]];
    }
    if (maxf >= k)
    {
        cout << 0;
        return 0;
    }





    return 0;
}

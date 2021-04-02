#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

string a, b;
vector <ll> poz;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("strmatch.in");
    //ofstream cout("strmatch.out");

    cin >> a >> b;
    ll n = a.length();
    ll m = b.length();
    ll k = 0;
    ll pi[n + 1];
    pi[1] = 0;

    for (ll i = 2; i <= n; i++)
    {
        while ((k > 0) && (a[k + 1] != a[i]))
               k = pi[k];
        if (a[k + 1] == a[i])
            k = k + 1;
        pi[i] = k;
    }

    ll q = 0;
    for (ll i = 1; i <= m; i++)
    {
        while ((q > 0) && (a[q + 1] != b[i]))
            q = pi[q];
        if (a[q + 1] == b[i])
            q = q + 1;
        if (q == n)
            cout << i - n + 1;
    }

    return 0;
}

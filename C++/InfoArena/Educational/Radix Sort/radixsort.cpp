//BAZATA PE COUNTSORT

#include <bits/stdc++.h>
typedef unsigned long long ul;
typedef long long ll;
using namespace std;
#define pb push_back

ll n, a, b, c;

ll maxim(ll v[], ll n)
{
    ll mx = v[0];
    for (ll i = 1; i < n; i++)
        mx = max(mx, v[i]);
    return mx;
}

void countSort(ll v[], ll n, ll exp)
{
    ll output[n];
    ll i, cnt[256] = {0};

    for (i = 0; i < n; i++)
        cnt[(v[i] / exp) % 256]++;

    for (i = 1; i < 256; i++)
        cnt[i] += cnt[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[cnt[ (v[i]/exp)%256 ] - 1] = v[i];
        cnt[ (v[i]/exp)%256 ]--;
    }

    for (i = 0; i < n; i++)
        v[i] = output[i];
}

void radixSort(ll v[], ll n)
{
    ll mx = maxim(v, n);
    for (ll exp = 1; mx / exp > 0 ; exp *= 256)
        countSort(v, n, exp);
}

void create(ll v[], ll n)
{
    v[0] = b;
    for (ll i = 1; i < n; i++)
    {
        v[i] = (a * v[i-1] + b) % c;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("radixsort.in");
    ofstream cout("radixsort.out");

    cin >> n >> a >> b >> c;
    ll v[n];
    create(v, n);

    radixSort(v, n);

    for (ll i = 0; i < n; i += 10)
        cout << v[i] << " ";

return 0;
}

#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll n, a, b, c, v[10000005], out[10000005], bucket[270];

void radixSort()
{
    for (ll k = 0; k < 32; k += 8)
    {

        for (ll i = 0; i < 256; i++)
            bucket[i] = 0;

        for (ll i = 0; i < n; i++)
            bucket[(v[i] >> k) & 255]++;

        for (ll i = 1; i < 256; i++)
            bucket[i] += bucket[i - 1];

        for (ll i = n - 1; i >= 0; i--)
        {
            out[bucket[(v[i] >> k) & 255] - 1] = v[i];
            bucket[(v[i] >> k) & 255]--;
        }

        for (ll i = 0; i < n; i++)
            v[i] = out[i];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("radixsort.in");
    ofstream cout("radixsort.out");

    cin >> n >> a >> b >> c;
    v[0] = b;
    for (ll i = 1; i < n; i++)
        v[i] = (a * v[i-1] + b) % c;

    radixSort();

    for (ll i = 0; i < n; i += 10)
        cout << v[i] << " ";

    return 0;
}

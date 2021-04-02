#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

unsigned int n, a, b, c, v[10000005], out[10000005];

void create()
{
    v[0] = b;
    for (int i = 1; i < n; i++)
        v[i] = (1LL * a * v[i-1] + b) % c;
}

void radixSort()
{
    for (int k = 0; k < 32; k += 8)
    {
        unsigned int bucket[256];
        for (int i = 0; i < 256; i++)
            bucket[i] = 0;

        for (int i = 0; i < n; i++)
            bucket[(v[i] >> k) & 255]++;

        for (int i = 1; i < 256; i++)
            bucket[i] += bucket[i - 1];

        for (int i = n - 1; i >= 0; i--)
        {
            out[bucket[(v[i] >> k) & 255] - 1] = v[i];
            bucket[(v[i] >> k) & 255]--;
        }

        for (int i = 0; i < n; i++)
            v[i] = out[i];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("radixsort.in");
    ofstream cout("radixsort.out");

    cin >> n >> a >> b >> c;
    create();

    radixSort();

    for (int i = 0; i < n; i += 10)
        cout << v[i] << " ";

    return 0;
}

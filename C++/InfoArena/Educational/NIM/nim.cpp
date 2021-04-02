#include <bits/stdc++.h>
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll t, n;

int main(){
ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
ifstream cin("nim.in");
ofstream cout("nim.out");

cin >> t;
while (t--)
{
    cin >> n;
    ll a[n];
    ll xorsum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        xorsum = xorsum^a[i];
    }
    if (xorsum) cout << "DA\n";
    else cout << "NU\n";
}
return 0;
}

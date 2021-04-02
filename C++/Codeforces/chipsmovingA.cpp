#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

ll n;
cin >> n;

ll a[n];
ll x = 0; //odd
ll y = 0; //even

for (ll i = 0; i < n; i++)
{
    cin >> a[i];
    if (a[i] % 2) x++;
    else y++;
}

if (x >= y) cout << y;
else if (x < y) cout << x;

return 0;
}

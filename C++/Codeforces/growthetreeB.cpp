#include <bits/stdc++.h>
typedef unsigned int ui;
typedef long long ll;
using namespace std;

ll n, x, y;
ll a[100010];

int main(){
ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

cin >> n;
for (ll i = 0; i < n; i++)
{
    cin >> a[i];
}

sort(a, a + n);

ll mid = n / 2;
for (ll i = 0; i < mid; i++) y += a[i];
for (ll i = mid; i < n; i++) x += a[i];

cout << x * x + y * y;
return 0;
}

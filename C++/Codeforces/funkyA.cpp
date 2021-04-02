#include <bits/stdc++.h>
typedef unsigned int ui;
typedef long long ll;
using namespace std;

ll n;

bool iftrig(ll k)
{
   ll res = (-1 + sqrt(1 + 8 * k)) / 2;
   if ( res * (res + 1) == 2 * k) return 1;
   return 0;
}

int main(){
ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

cin >> n;

for (ll i = 1; i * (i + 1) <= n; i++)
{
    ll check = n - (i * (i + 1)) / 2;
    if (iftrig(check))
    {
        cout << "YES";
        return 0;
    }
}
cout << "NO";
return 0;
}

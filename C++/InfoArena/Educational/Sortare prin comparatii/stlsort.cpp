#include <bits/stdc++.h>
typedef unsigned int ui;
typedef long long ll;
using namespace std;

int main(){
ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
ifstream cin("algsort.in");
ofstream cout("algsort.out");

ll n;
cin >> n;

ll a[n];
for (ll i = 0; i < n; i++)
{
    cin >> a[i];
}

sort(a, a+n);

for (ll i = 0; i < n; i++)
{
    cout << a[i] <<" ";
}

return 0;
}

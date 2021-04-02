#include <bits/stdc++.h>
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll a,b,c,d,e,f;

int main(){
ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

cin >> a >> b >> c >> d >> e >> f;

ll sum = 0;

if (f >= e)  //f >= e
{
    ll m1 = min(b, min(c, d));
    sum += m1 * f;
    d -= m1;
    ll m2 = min(a, d);
    sum += m2 * e;
}
else
{
    ll m1 = min(a, d);
    sum += m1 * e;
    d -= m1;
    ll m2 = min(b, min(c, d));
    sum += m2 * f;
}

cout << sum;

return 0;
}

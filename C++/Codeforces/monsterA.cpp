#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    ll a, b, c, d, x;
    cin >> a >> b >> c >> d;

    x = (d - b) / (a - c);
    if ((b + a * x) == (d + c * x))
        cout << b + a * x;
    else
        cout << -1;

    return 0;
}

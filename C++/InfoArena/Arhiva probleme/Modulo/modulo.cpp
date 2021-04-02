#include <bits/stdc++.h>
typedef unsigned int ui;
typedef long long ll;
using namespace std;

ll a, b, c;

ll expon(ll a, ll b, ll c)
{
    if (b == 0) return 1;
    else if (b == 1) return a%c;
    else if (b % 2 == 0) return expon((a * a) % c, b / 2, c) % c;
    else return (a%c)*expon((a * a) % c, (b - 1) / 2, c) % c;
}



int main(){
ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
ifstream cin("modulo.in");
ofstream cout("modulo.out");

cin >> a >> b >> c;

cout << expon(a, b ,c);


return 0;
}

#include <bits/stdc++.h>
typedef unsigned int ui;
typedef long long ll;
using namespace std;

ll T, a, b, n;

ll XORn(ll a, ll b, ll n)
{
    if (n%3 == 0) return a;
    else if (n%3 == 1) return b;
    else
    {
        return a^b;
    }
}

int main(){

cin >> T;
for (ll i = 0; i < T; i++)
{
    cin >> a >> b >> n;
    cout << XORn(a, b, n) <<endl;
}

return 0;
}

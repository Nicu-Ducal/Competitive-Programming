#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll t, x, y;

bool solve(ll a, ll b){
    while (a != 1){
        ll div = __gcd(a, b);
        if (div == 1)
            return false;
        a /= div;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("eqset.in");
    ofstream cout("eqset.out");

    cin >> t;
    while(t--){
        cin >> x >> y;
        ll num = __gcd(x, y);
        if (x == 1 and y == 1){
            cout << "1\n"; continue;
        } else if (num == 1){
            cout << "0\n"; continue;
        }
        if (solve(x / num, num) and solve(y / num, num))
            cout << 1 << "\n";
        else cout << 0 << "\n";
    }

    return 0;
}

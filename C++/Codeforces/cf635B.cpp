#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define len length()
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll t, x, y, z, a, n, m;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> t;
    while(t--){
        bool ok = 0;
        cin >> x >> n >> m;

        if (x - 10 * m <= 0){
            cout << "YES\n";
            continue;
        }

        while(n--){
            x /= 2;
            x += 10;
            if (x <= 0){
                ok = 1;
                break;
            }
        }
        if (ok){
            cout << "YES\n";
            continue;
        }
        x -= 10 * m;
        if (x <= 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}

#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll t, a, b, c, n, lasta = -1, lastb = -1;
bool ok = 1;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> t;
    while(t--){
        ok = 1;
        cin >> n;
        lasta = -1, lastb = -1;
        for (ll i = 0; i < n; i++){
            cin >> a >> b;
            if (lasta == -1 and lastb == -1){
                lasta = a;
                lastb = b;
            }
            if (lasta <= a and lastb <= b and a >= b and (a - lasta) >= (b - lastb)){
                lasta = a;
                lastb = b;
            }
            else{
                ok = 0;
            }
        }
        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }


    return 0;
}

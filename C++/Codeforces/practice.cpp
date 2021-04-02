#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll n, s, a[2];
bool ok = 1;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n;
    for (ll i = 0; i < n; i++){
        cin >> s;
        if (s == 25)
            a[0]++;
        else if (s == 50)
            if (a[0] >= 1){
                a[0]--;
                a[1]++;
            }
            else
                ok = 0;
        else
            if (a[1] > 0 && a[0] > 0){
                a[1]--;
                a[0]--;
            }
            else if (a[0] >= 3){
                a[0] -= 3;
            }
            else
                ok = 0;
    }
    if (ok) cout << "YES";
    else cout << "NO";

    return 0;
}

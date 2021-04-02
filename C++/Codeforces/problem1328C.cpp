#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

const int maxN = 5e5+5;
ll t, n;
char x[maxN], a[maxN], b[maxN];
bool ok = 0;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> t;
    while(t--){
        ok = 0;
        cin >> n >> x;
        for(ll i = 0; i < n; i++){
            if (ok){
                a[i] = '0';
                b[i] = x[i];
                continue;
            }
            if (x[i] == '0')
                a[i] = b[i] = '0';
            else if (x[i] == '2'){
                a[i] = b[i] = '1';
            }
            else{
                a[i] = '1';
                b[i] = '0';
                ok = 1;
            }
        }
        for (ll i = 0; i < n; i++)
            cout << a[i];
        cout << "\n";
        for (ll i = 0; i < n; i++)
            cout << b[i];
        cout << "\n";

    }
    return 0;
}

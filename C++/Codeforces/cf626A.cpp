#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    ll t, n;
    cin >> t;
    while(t--){
        cin >> n;
        ll a[n], temp1 = -1, temp2 = -1;
        bool ok = 0;
        for(ll i = 0; i < n; i++){
            cin >> a[i];
            if (!ok){
                if (a[i] % 2 == 0){
                    ok = 1;
                    temp1 = i;
                }
                else if (a[i] % 2 == 1 && temp1 == -1)
                    temp1 = i;
                else if (a[i] % 2 == 1 && temp1 != -1){
                    temp2 = i;
                    ok = 1;
                }
            }
        }
        if (temp2 != -1)
            cout << "2\n" << temp1 + 1 << ' ' << temp2 + 1 << "\n";
        else if (ok && temp2 == - 1)
            cout << "1\n" << temp1 + 1 << "\n";
        else
            cout << "-1\n";




    }

    return 0;
}

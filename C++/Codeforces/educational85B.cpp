#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll t, a[100005], b, c, x, n, negnum, pozsum, poznum;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> t;
    while(t--){
        pozsum = 0, negnum = -1, poznum = 0;
        cin >> n >> x;
        for (ll i = 0; i < n; i++){
            cin >> a[i];
            a[i] -= x;
            if (a[i] > 0){
                pozsum += a[i];
                poznum++;
            }
            else
                negnum++;
        }
        sort(a, a + n);

        for (ll i = negnum; i >= 0; i--){
            if (a[i] + pozsum >= 0){
                poznum++;
                pozsum += a[i];
            }
            else{
                break;
            }
        }

        cout << poznum << "\n";

    }

    return 0;
}

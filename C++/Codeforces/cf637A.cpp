#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define len length()
using ull = unsigned long long;
using ll = long long;
using namespace std;

ll t, n, a, b ,c, d;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> t;
    while(t--){
        cin >> n >> a >> b >> c >> d;
        if ((n * (a + b) < c - d) or (n * (a - b) > c + d))
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    return 0;
}

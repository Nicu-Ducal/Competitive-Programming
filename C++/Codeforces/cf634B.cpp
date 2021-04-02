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

ll t, n, a, b, c;
string s;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> t;
    while(t--){
        s = "";
        cin >> n >> a >> b;
        char c = 'a';
        for (ll i = 0; i < n; i++){
            s += c + i % b;
        }
        cout << s << "\n";
    }

    return 0;
}

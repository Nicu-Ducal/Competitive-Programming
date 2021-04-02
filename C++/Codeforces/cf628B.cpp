#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll t, n, a;
set <ll> s;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> t;
    while(t--){
        cin >> n;
        for(ll i = 0; i < n; i++){
            cin >> a;
            s.insert(a);
        }
        cout << s.size() << "\n";
        s.clear();
    }

    return 0;
}

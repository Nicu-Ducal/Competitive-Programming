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

ll t, n;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> t;
    while(t--){
        cin >> n;
        vector<int> v;
        if (n % 4 != 0)
        {
            cout << "NO\n";
            continue;
        }
        int num = 2;
        for (int i = 0; i < (n / 2); i++)
        {
            v.pb(num);
            num+=2;
        }
        v[n / 2 - 1] += n / 2;
        num = 3;
        for (int i = n/ 2; i < n; i++)
        {
            v.pb(num);
            num+=2;
        }
        cout << "YES\n";
        for(auto &it : v){
            cout << it << " ";
        }
        cout << '\n';
    }


    return 0;
}

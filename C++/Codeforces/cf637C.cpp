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

ll t, n;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> t;
    while (t--){
        cin >> n;
        ll a[n + 1], poz[n + 1];
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
            poz[a[i]] = i;
        }
        bool ok = 1;
        int num = 1;
        int right = n, left = 0;
        while (ok and num <= n){
            left = poz[num];
            if (left == right){
                --right;
                left = 0;
                ++num;
                continue;
            }
            else{
                int initleft = left;
                ++num;
                ++left;
                while (ok and left <= right){
                    if (a[left] == num){
                        ++num;
                        ++left;
                        if (left > right){
                            left = 0;
                            right = initleft - 1;
                            break;
                        }
                    }
                    else{
                        ok = 0;
                        break;
                    }
                }
                if (!ok) break;
            }
        }
        if (ok) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}

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
        ll a[n];
        ll ans = 0;
        deque<int> deq;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            if (deq.empty())
                deq.pb(a[i]);
            else{
                if ((deq.back() > 0 and a[i] > 0) or (deq.back() < 0 and a[i] < 0)){
                    if(!deq.empty() and deq.back() < a[i]){
                            deq.pop_back();
                            deq.pb(a[i]);
                    }
                }
                else{
                    ans += deq.front();
                    deq.pop_front();
                    deq.pb(a[i]);
                }
            }
        }
        if (!deq.empty())
            ans += deq.front();

        cout << ans << "\n";
    }
    return 0;
}

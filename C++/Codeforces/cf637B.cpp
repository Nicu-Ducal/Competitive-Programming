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

ll t, n, k, ans;
bool isPeak[200005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> t;
    while(t--){
        cin >> n >> k;
        ll a[n + 1];
        fill(isPeak, isPeak + n + 1, 0);
        for (ll i = 1; i <= n; i++){
            cin >> a[i];
        }
        for (ll i = 2; i <= n - 1; i++){
            if (a[i - 1] < a[i] and a[i] > a[i + 1])
                isPeak[i] = true;
        }
        ll ans, curr = 0;
        ll ansLeft = 1, currLeft = 1;
        for (ll i = 2; i < k; i++){
            if (isPeak[i]){
                curr++;
            }
        }
        ans = curr;
        for (int i = 2; i <= n - k + 1; i++){
            if (isPeak[i])
                curr--;
            if (isPeak[i + k - 2])
                curr++;
            if (ans < curr){
                ansLeft = i;
                ans = curr;
            }
        }
        cout << ans + 1 << " " << ansLeft << "\n";
    }
    return 0;
}


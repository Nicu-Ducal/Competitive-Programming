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

ll t, n, k;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> t;
    while(t--){
        cin >> n >> k;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }

        vector<int> frec(2 * k + 2);
        for (int i = 1; i <= n / 2; i++)
            ++frec[a[i] + a[n - i + 1]];

        vector<int> pref(2 * k + 2);
        for (int i = 1; i <= n / 2; i++){
            if (a[i] > a[n - i + 1])
                swap(a[i], a[n - i + 1]);
            int lo1 = a[i] + 1, hi1 = a[i] + k;
            int lo2 = a[n - i + 1] + 1, hi2 = a[n - i + 1] + k;
            ++pref[min(lo1, lo2)];
			--pref[max(hi1, hi2) + 1];
        }
        for (int i = 1; i <= 2 * k + 1; ++i)
			pref[i] += pref[i - 1];

        int ans = INT_MAX;
        for (int i = 2; i <= 2 * k; i++){
            ans = min(ans, (int) ((pref[i] - frec[i]) + (n / 2 - pref[i]) * 2));
        }

        cout << ans << "\n";
    }


    return 0;
}

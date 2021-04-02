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

ll t, n, a[2005], dp[2005][2005], j;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> t;
    while(t--){
        cin >> n;
        for (ll i = 0; i < n; i++){
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
            dp[i][i] = 1;
        for(int l = 2; l <= n; l++){
            for (int i = 0; i < n - l + 1; i++){
                j = i + l - 1;
                if(l == 2 && a[i] == a[j])
                    dp[i][j] = 2;

                else if(a[i] == a[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;

                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++)
                cout << dp[i][j] << " ";
            cout << "\n";
        }


        vector<ll> vec;
        vector<ll> tail;
        ll sol = dp[0][n - 1];
        int i = 0;
        j = n - 1;
        while(sol > 0){
            if (dp[i + 1][j] != sol and dp[i][j - 1] != sol){
                vec.pb(i);
                tail.pb(j);
                sol = dp[i + 1][j - 1];
            }
            if (dp[i + 1][j - 1] == sol){
                i++;
                j--;
            }
            else if (dp[i][j - 1] == sol)
                j--;

            else if (dp[i + 1][j] == sol)
                i++;
        }

        for (auto &it : vec){
            cout << it << " ";
        }
    }

    return 0;
}

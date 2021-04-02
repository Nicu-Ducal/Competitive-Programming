#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

const int maxNum = 105;
int suma[maxNum], v[maxNum][maxNum], m, n, k, ans, sum;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("blat.in");
    ofstream cout("blat.out");

    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++){
        for (int j = 1; j <= n; j++){
            cin >> v[i][j];
            suma[j] += v[i][j];
        }
        sort(v[i] + 1, v[i] + n + 1);
    }
    sort(suma + 1, suma + n + 1);

    for (int i = n; i > n - m; i--)
        ans += suma[i];
    cout << ans << "\n";

    ans = 0;
    for (int i = 1; i <= m; i++)
        ans += suma[i];
    cout << ans << "\n";

    int maxans = INT_MIN, minans = INT_MAX;
    for (int i = 1; i <= k; i++){
        ans = 0;
        for (int j = n; j > n - m; j--)
            ans += v[i][j];
        maxans = max(ans, maxans);

        ans = 0;
        for (int j = 0; j <= m; j++)
            ans += v[i][j];
        minans = min(ans, minans);
    }

    cout << maxans << "\n" << minans;

    return 0;
}

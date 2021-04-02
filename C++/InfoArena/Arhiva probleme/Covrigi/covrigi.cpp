#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

const int maxSz = 50005;
ll a[maxSz], c[maxSz], n, m, k, ans, p = 1;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("covrigi.in");
    ofstream cout("covrigi.out");

    cin >> n >> m >> k;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];

    for (ll i = 1; i <= m; i++){
        cin >> c[i];
        p += c[i];
    }

    sort(c + 1, c + m + 1, greater<int>());

    int i = 1;
    ll ans = a[p];
    while (c[i] != 0){
        p -= c[i];
        ll current = a[p] - i * k;
        ans = max(current, ans);
        i++;
    }

    cout << ans;

    return 0;
}

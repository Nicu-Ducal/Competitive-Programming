#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << "\n"
#define all(x) (x).begin(),(x).end()
#define len(x) (x).length()
#define size(x) (x).size()
#define sqr(x) (x) * (x)
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>

using ull = unsigned long long;
using ll = long long;
using namespace std;

template <typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B>
ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

const int INF = INT_MAX;
ll t, n, s, ans;

bool binary_search(vector<pii> &sal, ll chk) {
    ll cnt = 0, sum = 0;
    vector<pii> aux;
    for (int i = 0; i < n; i++) {
        if (sal[i].se < chk)
            sum += sal[i].fi;
        else if (sal[i].fi >= chk) {
            ++cnt;
            sum += sal[i].fi;
        } else {
            aux.pb(sal[i]);
        }
    }

    ll req = max(0LL, (n + 1) / 2 - cnt);
    if (req > size(aux))
        return false;

    for (int i = size(aux) - 1; i >= 0; i--) {
        if (req > 0) {
            sum += chk;
            --req;
        } else
            sum += aux[i].fi;
    }
    return sum <= s;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    cin >> t;
    while (t--) {
        cin >> n >> s;
        vector<pii> sal(n);
        ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> sal[i].fi >> sal[i].se;
        }
        sort(all(sal));

        ll lo = 1, hi = INF;
        while (lo <= hi) {
            ll mid = lo + (hi - lo) / 2;
            if (binary_search(sal, mid)) {
                ans = mid;
                lo = mid + 1;
            } else
                hi = mid - 1;
        }
        cout << ans << "\n";
    }


    return 0;
}

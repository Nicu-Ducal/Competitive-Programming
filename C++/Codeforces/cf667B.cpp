#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " = " << x << "\n"
#define all(x) (x).begin(),(x).end()
#define len(x) (x).length()
#define sqr(x) (x) * (x)

using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B>
ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

const int INF = INT_MAX;
const int MOD = 1e9 + 7;

ll t;
ll n;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    cin >> t;
    while(t--) {
        ll a, b, x, y;
        cin >> a >> b >> x >> y >> n;
        if (a > b)
            swap(a, b), swap(x, y);

        ll k = a - x, z = b - y;
        ll fi = (a - min(k, n)) * (b - min(z, n - min(k, n)));
        ll se = (a - min(k, n - min(z, n))) * (b - min(z, n));
        cout << min(fi, se) << "\n";
    }

    return 0;
}

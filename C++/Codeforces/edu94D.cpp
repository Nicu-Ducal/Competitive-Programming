#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define debug(x) cerr << #x << " = " << x << "\n"
#define all(x) (x).begin(),(x).end()
#define len(x) (x).length()
#define sqr(x) (x) * (x)
#define pb push_back
#define fi first
#define se second

using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; /// Ordered Set : find_by_order, order_of_key
template <typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B>
ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

const int INF = INT_MAX;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1);
ll t, n;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n), cnt(n * n + n + 1, 0);
        ll ans = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++)
                ++cnt[a[i] * n + a[j]];

            int k = i - 1;
            for (int j = 0; j < k; j++)
                ans += cnt[a[j] * n + a[k]];
        }

        cout << ans << "\n";
    }

    return 0;
}

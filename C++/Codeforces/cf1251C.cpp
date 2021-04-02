#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define debug(x) cerr << #x << " = " << x << "\n"
#define all(x) (x).begin(),(x).end()
#define len(x) (x).length()
#define size(x) (x).size()
#define sqr(x) (x) * (x)
#define pb push_back
#define fi first
#define se second

using ull = unsigned long long;
using ll = long long;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; /// Ordered Set : find_by_order, order_of_key
template <typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B>
ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

const int INF = INT_MAX, MOD = 1e9 + 7;
ll t, n;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    cin >> t;
    while (t--) {
        string a, imp, par, ans;
        cin >> a;
        n = len(a);
        for (int i = 0; i < n; i++) {
            if ((a[i] - '0') & 1) imp += a[i];
            else par += a[i];
        }

        int i = 0, j = 0;
        while (i < len(imp) and j < len(par)) {
            if (imp[i] < par[j]) {
                ans += imp[i];
                i++;
            } else {
                ans += par[j];
                j++;
            }
        }

        if (i < len(imp))
            ans += imp.substr(i, len(imp) - i);
        if (j < len(par))
            ans += par.substr(j, len(par) - j);

        cout << ans << "\n";
    }

    return 0;
}

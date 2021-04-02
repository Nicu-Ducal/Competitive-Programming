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

const ll INF = INT_MAX, maxN = 200000;
ll t, n, m, ans, a, b, val;
vector<ll> seg, lazy;

void update(ll lo, ll hi, ll idx, ll lf, ll rg, ll val) {
    if (lazy[idx] != 0) {
        seg[idx] += lazy[idx];
        if (lo != hi) {
            lazy[2 * idx + 1] += lazy[idx];
            lazy[2 * idx + 2] += lazy[idx];
        }
        lazy[idx] = 0;
    }

    if (rg < lo or lf > hi)
        return;
    if (lf <= lo and hi <= rg) {
        if (seg[idx] == INF)
            seg[idx] = val;
        else
            seg[idx] += val;
        if (lo != hi) {
            lazy[2 * idx + 1] += val;
            lazy[2 * idx + 2] += val;
        }
        return;
    }
    ll mid = lo + (hi - lo) / 2;
    update(lo, mid, 2 * idx + 1, lf, rg, val);
    update(mid + 1, hi, 2 * idx + 2, lf, rg, val);
    seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
}

ll query(ll lo, ll hi, ll idx, ll lf, ll rg) {
    if (lazy[idx] != 0) {
        seg[idx] += lazy[idx];
        if (lo != hi) {
            lazy[2 * idx + 1] += lazy[idx];
            lazy[2 * idx + 2] += lazy[idx];
        }
        lazy[idx] = 0;
    }

    if (rg < lo or lf > hi)
        return INF;
    if (lf <= lo and hi <= rg)
        return seg[idx];

    ll mid = lo + (hi - lo) / 2;
    return min(query(lo, mid, 2 * idx + 1, lf, rg), query(mid + 1, hi, 2 * idx + 2, lf, rg));
}

int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    cin >> n;
    seg.resize(4 * n, INF), lazy.resize(4 * n, 0);
    for (int i = 0; i < n; i++) {
        cin >> m;
        update(0, n - 1, 0, i, i, m);
    }

    cin >> t;
    while (t--) {
        cin >> a >> b;
        char c = getchar();
        if (c == ' ') {
            cin >> val;
            if (a <= b) {
                update(0, n - 1, 0, a, b, val);
            } else {
                update(0, n - 1, 0, a, n - 1, val);
                update(0, n - 1, 0, 0, b, val);
            }
        } else {
            if (a <= b) {
                cout << query(0, n - 1, 0, a, b) << "\n";
            } else {
                cout << min(query(0, n - 1, 0, a, n - 1), query(0, n - 1, 0, 0, b)) << "\n";
            }
        }
    }

    return 0;
}

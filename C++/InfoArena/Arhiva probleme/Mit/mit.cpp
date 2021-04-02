/******** Ordered Set ********
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; */

#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << "\n"
#define all(x) (x).begin(),(x).end()
#define len length()
#define sz size()
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>

using ull = unsigned long long;
using ll = long long;
using namespace std;

const int INF = INT_MAX, maxN = 1e5 + 5;
ll t, n, q, x, y, val, a[maxN], aint[4 * maxN], lay_Z[4 * maxN];

void create(ll lo, ll hi, ll pos){
    if (lo == hi)
        aint[pos] = a[lo];
    else {
        ll mid = lo + (hi - lo) / 2;
        create(lo, mid, 2 * pos + 1);
        create(mid + 1, hi, 2 * pos + 2);
        aint[pos] = max(aint[2 * pos + 1], aint[2 * pos + 2]);
    }
}

void update(ll idx, ll lo, ll hi, ll pos1, ll pos2, ll val){
    if (lay_Z[idx] != 0){
        aint[idx] += lay_Z[idx];
        if (lo != hi){
            lay_Z[2 * idx + 1] += lay_Z[idx];
            lay_Z[2 * idx + 2] += lay_Z[idx];
        }
        lay_Z[idx] = 0;
    }
    if (pos1 > hi or pos2 < lo)
        return;

    if (pos1 <= lo and hi <= pos2){
        aint[idx] += val;
        if (lo != hi){
            lay_Z[2 * idx + 1] += val;
            lay_Z[2 * idx + 2] += val;
        }
        return;
    } else {
        ll mid = lo + (hi - lo) / 2;
        update(2 * idx + 1, lo, mid, pos1, pos2, val);
        update(2 * idx + 2, mid + 1, hi, pos1, pos2, val);
        aint[idx] = max(aint[2 * idx + 1], aint[2 * idx + 2]);
    }
}

ll query(ll idx, ll lo, ll hi, ll pos1, ll pos2){
    if (lay_Z[idx] != 0){
        aint[idx] += lay_Z[idx];
        if (lo != hi){
            lay_Z[2 * idx + 1] += lay_Z[idx];
            lay_Z[2 * idx + 2] += lay_Z[idx];
        }
        lay_Z[idx] = 0;
    }

    if (pos1 > hi or pos2 < lo)
        return 0;

    if (pos1 <= lo and hi <= pos2)
        return aint[idx];

    ll mid = lo + (hi - lo) / 2;
    return max(query(2 * idx + 1, lo, mid, pos1, pos2), query(2 * idx + 2, mid + 1, hi, pos1, pos2));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("mit.in");
    ofstream cout("mit.out");

    cin >> n >> t;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    create(0, n - 1, 0);
    while (t--){
        cin >> q;
        switch (q){
            case 1:
                cin >> x >> y;
                cout << query(0, 0, n - 1, --x, --y) << "\n";
                break;
            case 2:
                cin >> x >> y >> val;
                update(0, 0, n - 1, --x , --y, val);
        }
    }

    return 0;
}

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

template<typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B>
ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

const int INF = INT_MAX;
ll t, n, m, q, k;

ll binarysearch0(vector<ll> &v, ll x){
    int lo = 0, hi = (int) v.size() - 1, ans = -2;
    while (lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if (v[mid] == x){
            ans = mid;
            lo = mid + 1;
        } else if (v[mid] < x){
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}

ll binarysearch1(vector<ll> &v, ll x){
    int lo = 0, hi = (int) v.size() - 1, ans = 0;
    while (lo < hi){
        int mid = lo + (hi - lo) / 2;
        if (v[mid] == x){
            ans = mid;
            lo = mid + 1;
        } else if (v[mid] < x){
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    if (v[lo] > x)
        ans = lo - 1;
    else
        ans = lo;
    return ans;
}

ll binarysearch2(vector<ll> &v, ll x){
    int lo = 0, hi = (int) v.size() - 1, ans = hi;
    while (lo < hi){
        int mid = lo + (hi - lo) / 2;
        if (v[mid] == x){
            ans = mid;
            hi = mid - 1;
        } else if (v[mid] < x){
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    if (v[lo] < x)
        ans = lo + 1;
    else
        ans = lo;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ifstream cin("cautbin.in");
    ofstream cout("cautbin.out");

    cin >> n;
    vector<ll> v(n, 0);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    cin >> m;
    while(m--){
        cin >> q >> k;
        switch (q){
            case 0:
                cout << binarysearch0(v, k) + 1 << "\n";
                break;
            case 1:
                cout << binarysearch1(v, k) + 1 << "\n";
                break;
            case 2:
                cout << binarysearch2(v, k) + 1 << "\n";
        }
    }

    return 0;
}

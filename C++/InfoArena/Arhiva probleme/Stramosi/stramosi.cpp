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

const int INF = INT_MAX, maxN = 250010;
int t, n, m, q, p, dp[maxN][21];

int query(int nod, int k){
    int bit = 0;
    while (k > 0) {
        if (k & 1) {
            nod = dp[nod][bit];
            if (!nod) return 0;
        }
        ++bit;
        k >>= 1;
    }
    return nod;
}

int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ifstream cin("stramosi.in");
    ofstream cout("stramosi.out");

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> dp[i][0];
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 20; j++){
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }

    while (m--){
        cin >> q >> p;
        cout << query(q, p) << "\n";
    }

    return 0;
}

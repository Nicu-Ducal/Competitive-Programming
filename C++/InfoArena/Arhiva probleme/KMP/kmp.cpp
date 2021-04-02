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

const ll INF = INT_MAX, MOD = 1000000007, p = 31;
ll t, n, lena, lenb;
string a, b;
vector<ll> ans, p_pow;

void rollingHash(string a, string b){
    p_pow.resize(lenb);
    p_pow[0] = 1;
    for (int i = 1; i < (int) p_pow.size(); i++)
        p_pow[i] = (p_pow[i - 1] * p) % MOD;

    vector<ll> h(lenb + 1, 0);
    for (int i = 0; i < lenb; i++)
        h[i + 1] = (h[i] + (ll)b[i] * p_pow[i]) % MOD;
    ll h_s = 0;
    for (int i = 0; i < lena; i++)
        h_s = (h_s + (ll)a[i] * p_pow[i]) % MOD;

    for (int i = 0; i + lena - 1 < lenb; i++){
        ll cur_h = (h[i + lena] + MOD - h[i]) % MOD;
        if (cur_h == h_s * p_pow[i] % MOD)
            if (ans.size() < 1000) ans.pb(i);
    }
}

int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    //ifstream cin("strmatch.in");
    //ofstream cout("strmatch.out");

    cin >> a >> b;
    lena = (ll) a.len, lenb = (ll) b. len;
    if (lena > lenb){ cout << 0; return 0; }
    else rollingHash(a, b);

    cout << ans.size() << "\n";
    for (auto num : ans)
        cout << num << " ";
    return 0;
}

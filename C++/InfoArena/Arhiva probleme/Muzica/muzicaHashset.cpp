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

const int INF = INT_MAX;
ll t, n, m, a, b, c, d, e, curr, ans;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

unordered_set<int, custom_hash> hsh;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("muzica.in");
    ofstream cout("muzica.out");

    cin >> n >> m;
    cin >> a >> b >> c >> d >> e;
    for (int i = 1; i <= n; i++){
        cin >> curr;
        hsh.insert(curr);
    }

    for (int i = 1; i <= m; i++){
        if (i == 1){
            curr = a;
        } else if (i == 2){
            curr = b;
        } else {
            curr = (c * b + d * a) % e;
            a = b, b = curr;
        }
        if (hsh.find(curr) != hsh.end()){
            ++ans;
            hsh.erase(curr);
        }
    }
    cout << ans;

    return 0;
}

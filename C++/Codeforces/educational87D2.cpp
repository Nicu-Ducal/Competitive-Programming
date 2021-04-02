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

const int INF = INT_MAX, maxN = 1e6 + 100, maxStep = (1 << 20);
int t, n, q, x, sum;
vector<int> bit(maxN, 0);

void update(int i, int val){
    while (i <= n){
        bit[i] += val;
        i += (-i & i);
    }
}

int query(int i){
    int ans = 0;
    while (i > 0){
        ans += bit[i];
        i -= (-i & i);
    }
    return ans;
}

void printBIT(){
    for (int i = 1; i <= n; i++){
        cout << query(i) << " ";
    }
    cout << '\n';
}

int binarySearch(int val){
    int step = maxStep, idx = 0;
    while (step > 0){
        if (idx + step < n and bit[idx + step] < val){
            idx += step;
            val -= bit[idx];
        }
        step >>= 1;
    }
    idx++;
    return idx;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> t;
    for (int i = 0; i < n; i++){
        cin >> x;
        update(x, 1);
        ++sum;
    }
    while (t--){
        cin >> q;
        if (q > 0)
            update(q, 1), ++sum;
        else{
            int k = binarySearch(-q);
            update(k, -1);
            --sum;
        }
    }
    if (sum == 0)
        cout << "0\n";
    else
        cout << binarySearch(sum);

    return 0;
}

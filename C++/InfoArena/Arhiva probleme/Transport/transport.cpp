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
ll t, n, k, a[16005], sum, ans = INF;

bool check(int num){
    int kSum = 0, tk = 1;
    for (int i = 0; i < n; i++){
        if (a[i] > num)
            return false;
        if (kSum + a[i] <= num){
            kSum += a[i];
        } else {
            ++tk;
            kSum = a[i];
        }
    }
    if (tk <= k) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("transport.in");
    ofstream cout("transport.out");

    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    ll lo = 0; ll hi = sum;
    while (lo <= hi){
        ll mid = lo + (hi - lo) / 2;
        if (check(mid)){
            ans = min(ans, mid);
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    cout << ans;
    return 0;
}

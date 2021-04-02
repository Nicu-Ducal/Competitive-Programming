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
ll a, b, t, n;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> t;
    while (t--){
        a = 0, b = 0;
        cin >> n;
        a += (1 << n);
        for (int i = n - 1; i > n / 2 - 1; i--)
            b += (1 << i);
        for (int i = n / 2 - 1; i >= 1; i--)
            a += (1 << i);
        cout << abs(a - b) << "\n";
    }


    return 0;
}

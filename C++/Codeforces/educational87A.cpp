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
ll t, n, a, b, c, d;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> t;
    while(t--){
        cin >> a >> b >> c >> d;
        if (b >= a){
            cout << b << '\n';
            continue;
        }
        if (d >= c){
            cout << -1 << "\n";
            continue;
        }
        n = b;
        a -= b;
        ll temp = c - d;
        temp = a / temp + (a % temp != 0);
        n += temp * c;
        cout << n << "\n";
    }

    return 0;
}

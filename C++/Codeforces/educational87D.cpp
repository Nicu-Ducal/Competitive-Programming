#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << "\n"
#define all(x) (x).begin(),(x).end()
//#define len length()
#define sz size()
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_multiset = tree<T, null_type, std::greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

using ull = unsigned long long;
using ll = long long;
using namespace std;

const int INF = INT_MAX;
ll t, n, q, a;

ordered_multiset<int> ms;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n >> q;
    for (int i = 0; i < n; i++){
        cin >> a;
        ms.insert(a);
    }
    while (q--){
        cin >> a;
        auto it1 = ms.lower_bound(a);
        auto it2 = ms.upper_bound(a);

        debug(*it1);
        debug(*it2);

        for (auto it : ms){
            cout << it << " ";
        }
        cout << "\n";
    }



    return 0;
}

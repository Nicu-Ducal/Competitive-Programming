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
ll t, n, x, y;
unordered_map<int, int> onX, onY;
vector<pii> points;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("flori2.in");
    //ofstream cout("flori2.out");

    cin >> t;
    while (t--){
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> x >> y;
            onX[x]++;
            onY[y]++;
            points.emplace_back(x, y);
        }
        sort(all(x), [](int pair1, int pair2){ return })
    }

    return 0;
}

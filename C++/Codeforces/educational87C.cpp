/******** Ordered Set ********
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; */

#define _USE_MATH_DEFINES
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
ll t;
double n, a, angle;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> t;
    while(t--){
        cin >> n;
        n *= 2;
        angle = ((n - 2) / n) * 180;

        double aux_side = ((n / 2) - 1) / 2;
        if (aux_side == 1)
            a = (sqrt(3) + 1.0) / sqrt(2);
        else{
            double center_ang = 180 - angle;
            a = 1.0 / sqrt(2) + (0.5 / cos(M_PI * (angle / 2) / 180.0)) * sin(M_PI * center_ang / 180.0) / sin(M_PI * 45 / 180.0);
        }

        cout << fixed << setprecision(7) << a << "\n";
    }

    return 0;
}

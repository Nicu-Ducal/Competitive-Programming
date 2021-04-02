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

struct point{
    double x, y;
};

const int INF = INT_MAX;
int n, x, y, ans;
point points[1005];
double dp[1005][1005];
unordered_map<double, pair<point, point>> mp;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("patrate3.in");
    //ofstream cout("patrate3.out");

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> points[i].x >> points[i].y;
    }
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){

        }
    }

    return 0;
}

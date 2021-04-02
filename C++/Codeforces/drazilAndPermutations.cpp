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
ll t, n, ans[10];
string a;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n >> a;
    for (int i = 0; i < n; i++){
        if (a[i] == '0' or a[i] == '1')
            continue;
        else if (a[i] == '2' or a[i] == '3' or a[i] == '5' or a[i] == '7')
            ++ans[a[i] - '0'];
        else if (a[i] == '4'){
            ans[2] += 2;
            ++ans[3];
        }
        else if (a[i] == '6'){
            ++ans[3], ++ans[5];
        } else if (a[i] == '8')
            ans[2] += 3, ++ans[7];
        else
            ans[3] += 2, ++ans[2], ++ans[7];
    }
    for (int i = 7; i > 1; --i){
        while(ans[i]--)
            cout << i;
    }

    return 0;
}

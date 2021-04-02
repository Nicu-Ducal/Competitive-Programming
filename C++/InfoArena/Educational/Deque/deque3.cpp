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
ll n, k, num, ans;
int deq[5000005], idx[5000005], fr, bk;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("deque.in");
    ofstream cout("deque.out");

    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> num;
        if (i == 1){
            deq[bk] = num, idx[bk] = i;
            continue;
        }
        while (fr <= bk and i - idx[fr] >= k)
            ++fr;
        while (fr <= bk and deq[bk] > num)
            --bk;
        deq[++bk] = num, idx[bk] = i;
        if (i >= k)
            ans += deq[fr];
    }
    cout << ans;
    return 0;
}

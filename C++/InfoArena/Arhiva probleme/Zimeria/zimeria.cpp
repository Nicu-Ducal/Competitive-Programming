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

const int INF = INT_MAX, MAXN = 400005;
ll t, n, p;
string a[MAXN], ord;
unordered_set<string> s;
unordered_map<char, char> bij;
unordered_map<char, char> inv;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("zimeria.in");
    ofstream cout("zimeria.out");

    cin >> p >> n >> ord;
    if (p == 2){
        char curr = 'a';
        for (int i = 0; i < ord.len; i++){
            bij[ord[i]] = curr;
            inv[curr] = ord[i];
            curr++;
        }
    }
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (p == 1) s.insert(a[i]);
        else {
            for (int j = 0; j < a[i].len; j++)
                a[i][j] = bij[a[i][j]];
        }
    }
    if (p == 1){
        cout << s.size();
    } else {
        sort(a, a + n);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < a[i].len; j++)
                a[i][j] = inv[a[i][j]];
            cout << a[i] << "\n";
        }
    }
    return 0;
}

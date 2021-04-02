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
ll t, n, ans, currMax, idx;
string s;
stack<pair<char, int>> stk;
vector<bool> seq;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("paranteze.in");
    ofstream cout("paranteze.out");

    cin >> n >> s;
    stk.push({s[0], 0});
    seq.resize(n, 0);
    pair<char, int> top;
    for (int i = 1; i < n; i++){
        if (!stk.empty()) top = stk.top();
        if (s[i] == '(' or s[i] == '{' or s[i] == '['){
            stk.push({s[i], i});
        } else if (!stk.empty() and ((s[i] == ')' and top.fi == '(') or (s[i] == ']' and top.fi == '[') or (s[i] == '}' and top.fi == '{'))){
            stk.pop();
            seq[i] = seq[top.se] = true;
        } else{
            stk.push({s[i], i});
        }
    }
    while (idx < n){
        if (seq[idx] and seq[idx + 1]) ++currMax;
        else ans = max(++currMax, ans), currMax = 0;
        ++idx;
    }
    cout << ans;
    return 0;
}

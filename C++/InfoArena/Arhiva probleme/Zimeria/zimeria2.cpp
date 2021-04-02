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

const int INF = INT_MAX, MAXNUM = 250000;
int ans, n, p, cnt[MAXNUM], mp[30];
string s, ord;

int toNum(string s){
    int ret = 0;
    int pw = 12 * 12 * 12 * 12;
    for (int i = 0; i < 5; i++){
        ret += pw * mp[s[i] - 'a'];
        pw /= 12;
    }
    return ret;
}

string toString(int num){
    string ret = "00000";
    for (int i = 4; i >= 0; i--){
        ret[i] = ord[num % 12];
        num /= 12;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("zimeria.in");
    ofstream cout("zimeria.out");

    cin >> p >> n >> ord;
    for (int i = 0; i < 12; i++){
        mp[ord[i] - 'a'] = i;
    }
    for (int i = 0; i < n; i++){
        cin >> s;
        int num = toNum(s);
        ++cnt[num];
        if (cnt[num] == 1)
            ++ans;
    }
    if (p == 1)
        cout << ans;
    else{
        for (int i = 0; i < MAXNUM; i++){
            if (cnt[i]){
                s = toString(i);
                while(cnt[i]--)
                    cout << s << "\n";
            }
        }
    }
    return 0;
}

#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define debug(x) cerr << #x << " = " << x << "\n"
#define all(x) (x).begin(),(x).end()
#define len(x) (x).length()
#define size(x) (x).size()
#define sqr(x) (x) * (x)
#define pb push_back
#define fi first
#define se second

using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; /// Ordered Set : find_by_order, order_of_key
template <typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B>
ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

const int INF = INT_MAX;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1);
ll t, n;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    cin >> t;
    while (t--) {
        int x;
        string s, w = "";
        vector<bool> ok;
        bool good = true;
        cin >> s >> x;

        ok.resize(len(s), false);
        for (int i = 0; i < len(s); i++)
            w += "1";
        int n = len(s);
        for (int i = 0; i < len(s); i++) {
            if (i - x >= 0 and i + x < n) {
                if (s[i] == '0') {
                    if (ok[i - x] == false) {
                        w[i - x] = '0';
                        ok[i - x] = true;
                    } else {
                        if (w[i - x] == '1') {
                            good = false;
                            break;
                        }
                    }
                    if (ok[i + x] == false) {
                        w[i + x] = '0';
                        ok[i + x] = true;
                    } else {
                        if (w[i + x] == '1') {
                            good = false;
                            break;
                        }
                    }
                } else {
                    if (ok[i - x] == false) {
                        w[i - x] = '1';
                        ok[i - x] = true;
                    } else {
                        if (w[i - x] == '0') {
                            if (ok[i + x] == false) {
                                w[i + x] = '1';
                                ok[i + x] = true;
                            } else {
                                if (w[i + x] == '0') {
                                    good = false;
                                    break;
                                }
                            }
                        }
                    }
                }
            } else if (i - x < 0 and i + x < n) {
                w[i + x] = s[i];
                ok[i + x] = true;
            } else if (i + x >= n and i - x >= 0) {
                if (ok[i - x] == false) {
                    w[i - x] = s[i];
                    ok[i - x] = true;
                } else {
                    if (w[i - x] != s[i]) {
                        good = false;
                        break;
                    }
                }
            } else if (i + x >= n and i - x < 0) {
                if (s[i] != '0') {
                    good = false;
                    break;
                }
            }
        }
        //cout << ok << "\n";
        if (good)
            cout << w << "\n";
        else
            cout << "-1\n";
    }

    return 0;
}

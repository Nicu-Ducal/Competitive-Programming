#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " = " << x << "\n"
#define all(x) (x).begin(),(x).end()
#define len(x) (x).length()
#define sqr(x) (x) * (x)

using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B>
ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

const int INF = INT_MAX;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1);

ll t, n;

template<typename T>
struct fenwick_tree {
    int tree_n = 0;
    vector<pair<T, int>> tree;

    fenwick_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        tree_n = n;
        tree.resize(tree_n + 1, {0, -1});
    }

    void update(int idx, int val) {
        int prev = idx;
        while (idx <= n) {
            if (tree[idx].first < val)
                tree[idx] = {val, prev};
            idx += (-idx & idx);
        }
    }

    pair<T, int> get(int idx) {
        int ans = 0, i = -1;
        while (idx > 0) {
            if (tree[idx].first > ans) {
                ans = tree[idx].first;
                i = tree[idx].second;
            }
            idx -= (-idx & idx);
        }

        return {ans, i};
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ifstream cin("scmax.in");
    ofstream cout("scmax.out");

    cin >> n;
    unordered_map<int, int> pos;
    vector<int> a(n), s(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s[i] = a[i];
    }

    // Creating the index array
    sort(all(s));
    for (int i = 1; i <= n; i++)
        pos[s[i - 1]] = i;
    s.resize(0);
    for (int i = 0; i < n; i++)
        if (s.size() == 0 or (s.size() > 0 and s.back() != pos[a[i]]))
            s.push_back(pos[a[i]]);


    // Longest increasing subsequence
    fenwick_tree<int> fw(n);
    vector<int> dp(s.size(), 1), prev(n, -1);
    for (int i = 0; i < s.size(); i++) {
        pair<int, int> p = fw.get(s[i] - 1);
        // cout << i << ' ' << p << "\n";
        dp[i] = 1 + p.first;
        prev[s[i]] = p.second;
        fw.update(s[i], dp[i]);
    }

    int ans = 1, posans = 1;
    for (int i = 0; i < s.size(); i++) {
        if (dp[i] > ans) {
            ans = dp[i];
            posans = s[i];
        }
    }

    sort(all(a));
    s.resize(0);
    while (posans != -1) {
        s.push_back(a[posans - 1]);
        posans = prev[posans];
    }

    cout << ans << "\n";
    for (int i = s.size() - 1; i >= 0; i--)
        cout << s[i] << " ";

    return 0;
}

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

/**
 *  Auhtor: Neeecu
 *  Algorithm: 2-SAT (using Strongly Connected Components)
 */
struct graph {
    vector<vector<int>> out, in;
    vector<bool> mark;
    vector<int> ord, comp;
    vector<int> ans;

    graph(int n = 0) {
        out.resize(n + 1);
        in.resize(n + 1);
        mark.resize(n + 1, false);
        comp.resize(n + 1, -1);
        ans.resize(n + 1, 0);
    }

    int complement(int x) {
        return ((x < 0) ? -x : n + x);
    }

    int index(int x) {
        return ((x < 0) ? n - x : x);
    }

    void add(int from, int to) {
        out[complement(from)].push_back(index(to));
        in[index(to)].push_back(complement(from));

        out[complement(to)].push_back(index(from));
        in[index(from)].push_back(complement(to));
    }

    void dfs_ord(int node) {
        if (mark[node]) return;
        mark[node] = true;

        for (auto next: out[node])
            dfs_ord(next);

        ord.push_back(node);
    }

    void dfs_comp(int node, int c) {
        if (comp[node] != -1) return;
        comp[node] = c;

        for (auto next: in[node])
            dfs_comp(next, c);
    }

    void solve2sat() {
        for (int i = 1; i <= n; i++) {
            ans[i] = comp[i] > comp[i + n];
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ifstream cin("2sat.in");
    ofstream cout("2sat.out");

    int m, x, y;
    cin >> n >> m;

    graph sat(2 * n);
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        sat.add(x, y);
    }

    // Make the order array
    for (int i = 1; i <= 2 * n; i++)
        sat.dfs_ord(i);
    sat.mark.assign(2 * n + 1, false);

    // Make strongly connected components
    int c = 1;
    for (int i = 2 * n - 1; i >= 0; i--) {
        if (sat.comp[sat.ord[i]] == -1) {
            sat.dfs_comp(sat.ord[i], c);
            c++;
        }
    }

    // Check if a solution exists:
    for (int i = 1; i <= n; i++) {
        if (sat.comp[i] == sat.comp[n + i]) {
            cout << "-1";
            return 0;
        }
    }

    // If we've reached here, it means a solution exists
    sat.solve2sat();
    for (int i = 1; i <= n; i++)
        cout << sat.ans[i] << " ";

    return 0;
}

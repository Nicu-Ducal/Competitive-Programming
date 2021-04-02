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

struct Tree {
    vector<vector<int>> adj;
    vector<bool> mark;
    int maxnode = 1, maxdist = 1;

    Tree(int n = 0) {
        adj.resize(n + 1);
        mark.resize(n + 1, false);
    }

    void add(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int node, int dist) {
        if (mark[node]) return;
        mark[node] = true;

        if (maxdist < dist) {
            maxdist = dist;
            maxnode = node;
        }

        for (auto next: adj[node])
            dfs(next, dist + 1);
    }

    int find_diameter() {
        // First we start a DFS from the root
        dfs(1, 1);
        mark.assign(n + 1, false);
        // Secondly, we make a DFS from the furthest node
        dfs(maxnode, 1);
        return maxdist;
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ifstream cin("darb.in");
    ofstream cout("darb.out");

    cin >> n;

    Tree tree(n);
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        tree.add(u, v);
    }

    cout << tree.find_diameter() << "\n";

    return 0;
}

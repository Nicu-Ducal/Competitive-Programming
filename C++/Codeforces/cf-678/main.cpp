#include <bits/stdc++.h>
using namespace std;

template <typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
using i64 = long long int;

const int INF = INT_MAX, MOD = 1e9 + 7;
const double EPS = 1e-9, PI = acos(-1);
const int dx[] = {0, 0, 0, -1, 1, -1, 1, 1, -1};
const int dy[] = {0, -1, 1, 0, 0, -1, 1, -1, 1};

struct Graph {
    vector<vector<int>> adj;
    vector<i64> pop, leaves, sum;
    vector<bool> marked;
    int n;

    Graph(int _n = 0) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        adj.resize(n + 1);
        pop.resize(n + 1);
        leaves.resize(n + 1);
        sum.resize(n + 1);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    /// Idea: To count the max number of citizens, just take the max of the sum[curent_node]/nr. of
    /// leaves that are in this subtree and curent maximum, which can be maximum of a leaf node
    i64 DFS(int node) {
        i64 mx = 0;
        if (adj[node].empty()) {
            leaves[node] = 1;
            sum[node] = pop[node];
            return pop[node];
        } else {
            for (auto next: adj[node]) {
                mx = max(mx, DFS(next));
                leaves[node] += leaves[next];
                sum[node] += sum[next];
            }
            sum[node] += pop[node];
            mx = max(mx, sum[node] / leaves[node] + (sum[node] % leaves[node] != 0));
            return mx;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    int n;
    cin >> n;
    Graph g(n);
    for (int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        g.addEdge(u, i);
    }
    for (int i = 1; i <= n; i++) cin >> g.pop[i];
    cout << g.DFS(1);

    return 0;
}
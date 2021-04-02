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
*   Author: Neeecu
*   Data structure: Disjoint Set Union
*/
struct DSU {
    vector<int> parent, rank, size;
    // rank of a vertex ~ height of its subtree
    // 1) size[x] >= 2 ^ rank[x]
    // 2) rank[p[x]] > rank[x], p[x] != x

    DSU(int _n = 0) {
        init(n);
    }

    void init(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1);
        size.resize(n + 1);
        for (int i = 1; i <= n; i++)
            make_set(i);
    }

    void make_set(int v) {
        parent[v] = v;
        rank[v] = 1;
    }

    // Union by rank (size is similar)
    void union_sets(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (rank[x] < rank[y])
                swap(x, y);
            parent[y] = x;
            if (rank[x] == rank[y])
                rank[x]++;
        }
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
};

struct Edge {
    int from, to, w;

    Edge(int _from, int _to, int _w) : from(_from), to(_to), w(_w) {}

    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

struct min_span_tree {
    // vector<vector<Edge>> adj;
    vector<Edge> adj, mst;
    DSU dsu;
    ll total_w = 0;

    min_span_tree(int n) {
        // adj.resize(n + 1);
        dsu.init(n);
        dsu.make_set(n);
    }

    void add_edge(int to, int from, int weight) {
        adj.push_back(Edge(from, to, weight));
        // adj.push_back(Edge(to, from, weight));
        // adj[to].push_back(Edge(to, from, weight));
        // adj[from].push_back(Edge(from, to, weight));
    }

    void create_mst() {
        sort(all(adj));
        for (auto e: adj) {
            if (dsu.find(e.to) != dsu.find(e.from)) {
                total_w += e.w;
                mst.push_back(e);
                dsu.union_sets(e.to, e.from);
            }
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ifstream cin("apm.in");
    ofstream cout("apm.out");

    ll m, from, to, w;
    cin >> n >> m;
    min_span_tree MST(n);
    for (int i = 1; i <= m; i++) {
        cin >> from >> to >> w;
        MST.add_edge(from, to, w);
    }

    MST.create_mst();

    cout << MST.total_w << "\n" << n - 1 << "\n";
    for (auto edg: MST.mst) cout << edg.from << " " << edg.to << "\n";

    return 0;
}

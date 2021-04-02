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
 *  Author: Neeecu
 *  Data structure: Segment Tree (max)
 */
template<typename T, bool lazy = false>
struct max_segment_tree {
    vector<T> tree;//, lazy, arr;
    int n;

    max_segment_tree(int _n = 0) {
        init(_n);
    }

    /*max_segment_tree(vector<T> _arr) : arr(_arr), n(arr.size()) {
        init(n);
        build(0, n - 1, 0);
    }*/

    void init(int n) {
        this->n = n;
        tree.resize(4 * n);
        //lazy.resize(4 * n, 0);
        //arr.resize(n, 0);
    }
/*
    void build(int l, int r, int pos) {
        if (l == r)
            tree[pos] = arr[l];
        else {
            int mid = l + (r - l) / 2;
            init(l, mid, 2 * pos + 1);
            init(mid + 1, r, 2 * pos + 2);
            tree[pos] = max(tree[2 * pos + 1], tree[2 * pos + 2]);
        }
    }*/

    void add(int idx, T val) {
        _update(val, idx, idx, 0, n - 1, 0);
    }

    void add(int l, int r, T val) {
        _update(val, l, r, 0, n - 1, 0);
    }

    void update(int idx, T val) {
        _update(val - query(idx, idx), idx, idx, 0, n - 1, 0);
    }

    void _update(int val, int l, int r, int li, int ri, int pos) {
        /*if (lazy and lazy[pos] != 0) {
            tree[pos] += lazy[pos];
            if (li != ri) {
                lazy[2 * pos + 1] += lazy[pos];
                lazy[2 * pos + 2] += lazy[pos];
            }
            lazy[pos] = 0;
        }*/

        if (ri < l or r < li)
            return;
        else if (l <= li and ri <= r) {
            tree[pos] += val;
            /*if (lazy and li != ri) {
                lazy[2 * pos + 1] += val;
                lazy[2 * pos + 2] += val;
            }*/
        } else {
            int mi = li + (ri - li) / 2;
            _update(val, l, r, li, mi, 2 * pos + 1);
            _update(val, l, r, mi + 1, ri, 2 * pos + 2);
            tree[pos] = max(tree[2 * pos + 1], tree[2 * pos + 2]);
        }
    }

    T query(int l, int r) {
        return _query(l, r, 0, n - 1, 0);
    }

    T _query(int l, int r, int li, int ri, int pos) {
        /*if (lazy and lazy[pos] != 0) {
            tree[pos] += lazy[pos];
            if (li != ri) {
                lazy[2 * pos + 1] += lazy[pos];
                lazy[2 * pos + 2] += lazy[pos];
            }
            lazy[pos] = 0;
        }*/

        if (r < li or ri < l)
            return LLONG_MIN;
        else if (l <= li and ri <= r)
            return tree[pos];
        else {
            int mi = li + (ri - li) / 2;
            return max(_query(l, r, li, mi, 2 * pos + 1), _query(l, r, mi + 1, ri, 2 * pos + 2));
        }
    }
};


/**
 *  Author: Neeecu
 *  Data structure: Heavy-Light Decomposition
 */
struct heavy_light {
    vector<int> value, parent, depth;
    vector<int> top, subtree_size, heavy, label;
    vector<vector<int>> adj;

    // Must declare with a struct/class already defined:
    max_segment_tree<int> seg;

    heavy_light(int n = -1) {
        init(n);
    }

    void init(int n) {
        value.resize(n + 1, 0);
        parent.resize(n + 1, -1);
        depth.resize(n + 1, 0);
        top.resize(n + 1);
        iota(top.begin(), top.end(), 0);
        subtree_size.resize(n + 1, 0);
        adj.resize(n + 1);
        heavy.resize(n + 1, -1);
        label.resize(n + 1, 0);

        seg.init(n + 1);
    }

    void add_edge(int from, int to) {
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    // Decompose the tree in heavy paths
    void build() {
        dfs_size(1, -1);
        dfs_top(1);
        dfs_label(1);
        //cout << seg.tree << "\n";
    }

    // Find heavy edges
    void dfs_size(int node, int par) {
        subtree_size[node] = 1;
        parent[node] = par;
        depth[node] = par < 0 ? 0 : depth[par] + 1;
        int heavy_child = -1, w = -1;

        for (auto next: adj[node]) {
            if (next != parent[node]) {
                dfs_size(next, node);
                subtree_size[node] += subtree_size[next];

                if (w < subtree_size[next]) {
                    heavy_child = next;
                    w = subtree_size[next];
                }
            }
        }

        heavy[node] = heavy_child;
    }

    // Finding top of every heavy path
    void dfs_top(int node) {
        if (heavy[node] != -1)
            top[heavy[node]] = top[node];

        for (auto next: adj[node])
            if (next != parent[node])
                dfs_top(next);
    }

    // Creating the segment tree (max, min, or sum)
    // Labeling nodes in such way that heavy paths end up together
    int label_index = 1;
    void dfs_label(int node) {
        label[node] = label_index++;
        seg.add(label[node], value[node]);

        // First the heavy node
        if (heavy[node] != -1)
            dfs_label(heavy[node]);

        for (auto next: adj[node])
            if (next != parent[node] and next != heavy[node])
                dfs_label(next);
    }

    // LCA of two nodes (simple O(log N) approach)
    int LCA(int u, int v) {
        if (top[u] == top[v])
            return (depth[u] < depth[v] ? u : v);

        if (depth[top[u]] < depth[top[v]])
            v = parent[top[v]];
        else
            u = parent[top[u]];
        return LCA(u, v);
    }

    // Queries
    int query(int u, int v) {
        int lca = LCA(u, v);
        return max(value[lca], max(queryup(u, lca), queryup(v, lca)));
    }

    // Returns the associative function in range [node, lca)
    int queryup(int node, int lca) {
        int x = top[node];
        if (depth[x] > depth[lca]) {
            return max(queryup(parent[x], lca), seg.query(label[x], label[node]));
        } else
            return seg.query(label[lca] + 1, label[node]);
    }

    void add(int node, int val) {
        int diff = val - value[node];
        value[node] += diff;
        seg.add(label[node], diff);
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ifstream cin("heavypath.in");
    ofstream cout("heavypath.out");

    int m;
    cin >> n >> m;

    heavy_light hld(n);
    for (int i = 1; i <= n; i++) {
        cin >> hld.value[i];
    }

    int from, to;
    for (int i = 1; i < n; i++) {
        cin >> from >> to;
        hld.add_edge(from, to);
    }

    hld.build();

    int q, x, y;
    while (m--) {
        cin >> q >> x >> y;
        if (q == 1) {
            cout << hld.query(x, y) << "\n";
        } else {
            hld.add(x, y);
        }
    }



    return 0;
}

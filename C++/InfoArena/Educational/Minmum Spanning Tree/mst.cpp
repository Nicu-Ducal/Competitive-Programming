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

// Algorithm: Prim's Algorithm - Minimum Spanning Tree
// Author: Neeecu
// Complexity: O(|E| * log|N|);

struct Edge {
    int from, to, w;

    Edge(int _from, int _to, int _w) : from(_from), to(_to), w(_w) {}

    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

struct min_span_tree {
    vector<vector<Edge>> adj;
    vector<Edge> mst;
    vector<bool> in_tree;
    vector<Edge> min_edge;
    ll total_w = 0;

    min_span_tree(int n) {
        adj.resize(n + 1);
        in_tree.resize(n + 1, false);
        min_edge.push_back(Edge(-1, -1, -1));
    }

    void add_edge(int to, int from, int weight) {
        adj[to].push_back(Edge(to, from, weight));
        adj[from].push_back(Edge(from, to, weight));
    }

    void create_mst() {
        in_tree[1] = true;
        min_edge.push_back(Edge(-1, 1, 0));
        set<pair<int, pair<int, int>>> s;
        s.insert({0, {-1, 1}});
        for (int i = 2; i <= n; i++){
            min_edge.push_back(Edge(-1, i, INF));
            s.insert({INF, {-1, i}});
        }

        while (not s.empty()) {
            auto t = *s.begin();
            Edge cur_edge = Edge(t.second.first, t.second.second, t.first);
            s.erase(s.begin());

            /// Add current edge to MST
            if (cur_edge.to != 1) {
                total_w += cur_edge.w;
                mst.push_back(Edge(cur_edge.from, cur_edge.to, cur_edge.w));
                in_tree[cur_edge.to] = true;
            }

            /// Update edges
            for (auto edg: adj[cur_edge.to]) {
                if (not in_tree[edg.to] and edg.w < min_edge[edg.to].w) {
                    s.erase({min_edge[edg.to].w, {min_edge[edg.to].from, min_edge[edg.to].to}});
                    min_edge[edg.to] = edg;
                    s.insert({min_edge[edg.to].w, {min_edge[edg.to].from, min_edge[edg.to].to}});
                }
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

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


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ifstream cin("disjoint.in");
    ofstream cout("disjoint.out");

    int m, q, x, y;
    cin >> n >> m;

    DSU dsu(n);

    while (m--) {
        cin >> q >> x >> y;
        if (q == 1) {
            dsu.union_sets(x, y);
        } else {
            cout << (dsu.find(x) == dsu.find(y) ? "DA\n" : "NU\n");
        }
    }

    return 0;
}

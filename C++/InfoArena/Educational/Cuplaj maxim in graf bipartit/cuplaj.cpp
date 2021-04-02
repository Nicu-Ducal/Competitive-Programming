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

struct BipartiteGraph {
    vector<vector<int>> adj;

    BipartiteGraph(int n = -1) {
        init(n);
    }

    void init(int n) {
        adj.resize(n + 1);
    }

    void addEdge(int u, int v) {

    }
};


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ifstream cin("cuplaj.in");
    /// ofstream cout("cuplaj.out");

    int m, e, u, v;
    cin >> n >> m >> e;
    BipartiteGraph bg(n);
    for (int i = 1; i <= e; i++) {
        cin >> u >> v;
        bg.addEdge(u, v);
    }
    return 0;
}

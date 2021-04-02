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
  vector<bool> marked;
  vector<int> parent, level;
  int n;
  i64 ans = i64(i64(n * (n - 1)) / 2);

  Graph(int _n = 0) {
    init(_n);
  }

  void init(int _n) {
    n = _n;
    ans = i64(i64(n * (n - 1)) / 2);
    adj.resize(n + 1);
    marked.resize(n + 1, false);
  }

  void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    Graph graph(n);
    for (int i = 0; i < n; i++) {
      int u, v;
      cin >> u >> v;
      graph.addEdge(u, v);
    }

  }

  return 0;
}
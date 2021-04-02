#include <bits/stdc++.h>
using namespace std;

template <typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

const int64_t INF = LLONG_MAX, MOD = 1e9 + 7;
const double EPS = 1e-9, PI = acos(-1);
const int dx[] = {0, 0, 0, -1, 1, -1, 1, 1, -1};
const int dy[] = {0, -1, 1, 0, 0, -1, 1, -1, 1};

struct Graph {
  vector<vector<int>> adj;
  vector<pair<int, int64_t>> edges;
  // vector<bool> marked;
  vector<int> ans;
  vector<int64_t> dist;
  int n, s, d;
  int64_t sum;

  Graph(int _n = 0, int _s = -1, int _d = -1) {
    init(_n, _s, _d);
  }

  void init(int _n, int _s, int _d) {
    n = _n; s = _s, d = _d;
    sum = 0;
    adj.assign(n + 1, vector<int>());
    edges.clear();
    // marked.resize(n + 1, false);
    dist.assign(n + 1, INF);
    ans.clear();
  }

  void addEdge(int u, int v, int64_t w) {
    edges.emplace_back(v, w);
    adj[u].push_back((int) edges.size() - 1);
    edges.emplace_back(u, w);
    adj[v].push_back((int) edges.size() - 1);
  }

  void Dijkstra() {
    priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> pq;
    dist[d] = 0LL;
    pq.emplace(0, d);
    while (not pq.empty()) {
      auto cur = pq.top();
      pq.pop();
      if (dist[cur.second] < cur.first) continue;
      int node = cur.second;
      for (auto next: adj[node]) {
        if (dist[edges[next].first] > dist[node] + edges[next].second) {
          dist[edges[next].first] = dist[node] + edges[next].second;
          pq.emplace(dist[edges[next].first], edges[next].first);
        }
      }
    }
  }

  void ComputeAnswer() {
    Dijkstra();
    // cout << sum << " " << edges << " " << dist << "\n";
    for (int node = 1; node <= n; node++)
      if (dist[node] <= sum)
        ans.push_back(node);
  }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  ifstream cin("tempest.in");
  ofstream cout("tempest.out");

  int t; cin >> t;
  Graph G;
  while (t--) {
    int64_t n, m, s, d;
    cin >> n >> m >> s >> d;
    G.init(n, s, d);
    for (int i = 0; i < m; i++) {
      int u, v; int64_t w;
      cin >> u >> v >> w;
      G.addEdge(u, v, w);
    }
    int64_t k, checked;
    cin >> k;
    while (k--) {
      cin >> checked;
      G.sum += G.edges[2 * checked - 1].second;
    }

    G.ComputeAnswer();
    cout << G.ans.size() << "\n";
    for (auto node: G.ans) cout << node << " ";
    cout << "\n";
  }

  return 0;
}
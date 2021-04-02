#include <bits/stdc++.h>
using namespace std;

template <typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
using i64 = long long int;

const int INF = INT_MAX, MOD = 1e9 + 7;
const double EPS = 1e-9, PI = acos(-1);
const int dx[] = {0, 0, 0, -1, 1, -1, 1, 1, -1};
const int dy[] = {0, -1, 1, 0, 0, -1, 1, -1, 1};

/// Undirected/directed graph (for directed delete a push_back from the addEdge
struct Graph {
  vector<vector<int>> adj;
  vector<bool> marked;
  vector<int> parent, level, dist;
  int n;

  Graph(int _n = 0) {
    init(_n);
  }

  void init(int _n) {
    n = _n;
    adj.resize(n + 1, vector<int>(n + 1, 0));
    dist.resize(n + 1, INF);
    marked.resize(n + 1);
  }

  void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
  }

  void Dijsktra(int node, int target, int road_type) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, node);
    dist[node] = 0;
    while (not pq.empty()) {
      auto current = pq.top();
      pq.pop();
      if (current.first > dist[current.second]) continue;
      node = current.second;
      for (int next = 1; next <= n; next++) {
        if (adj[node][next] == road_type) {
          if (dist[next] > dist[node] + 1) {
            dist[next] = dist[node] + 1;
            pq.emplace(dist[next], next);
          }
        }
      }
    }
  }

  int solve() {
    /// Idea: the adj[u][v] == 1 denotes a railroad, == 0 denotes a simple road
    int ans;
    if (adj[1][n] == 1)
      Dijsktra(1, n, 0), ans = max(1, dist[n]);
    else
      Dijsktra(1, n, 1), ans = max(1, dist[n]);
    // int ans = max(dist[0][n], dist[1][n]);
    return (ans == INF ? -1 : ans);
  }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  int N, M;
  cin >> N >> M;
  Graph graph(N);
  for (int i = 1; i <= M; i++) {
    int u, v;
    cin >> u >> v;
    graph.addEdge(u, v);
  }

  cout << graph.solve() << "\n";

  return 0;
}

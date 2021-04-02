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
  vector<vector<pair<int, int>>> adj;
  vector<int64_t> dist;
  vector<int> ans;
  int n;

  Graph(int _n = 0) {
    init(_n);
  }

  void init(int _n) {
    n = _n;
    adj.resize(n + 1);
    dist.resize(n + 1, INF);
    // ans.resize(n + 1, -1);
  }

  void addEdge(int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  int64_t Dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, start);
    dist[start] = 0;
    int64_t cost = INF;
    while (not pq.empty()) {
      auto cur = pq.top();
      pq.pop();
      if (dist[cur.second] < cur.first) continue;
      int node = cur.second;
      for (auto next: adj[node]) {
        if (dist[next.first] > dist[node] + next.second) {
          dist[next.first] = dist[node] + next.second;
          pq.emplace(dist[next.first], next.first);
        }
        // Check if the next node is the first one and choose the minimal positive distance
        if (next.first == start)
          cost = min(cost, dist[node] + next.second);
      }
    }
  }

  void run_task() {
    for (int node = 1; node <= 1; node++) {
      fill(dist.begin(), dist.end(), INF);
      int cost = Dijkstra(node);
      cout << dist << "\n";
      if (cost == 0) cout << "-1 ";
      else cout << cost << " ";
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  int n, m; cin >> n >> m;
  Graph G(n);
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    G.addEdge(u, v, w);
  }

  G.ComputePaths();

  return 0;
}
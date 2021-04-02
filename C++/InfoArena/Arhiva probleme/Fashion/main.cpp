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
  vector<vector<int>> adj, capacity;
  vector<int> parent, cut_source, cut_sink;
  vector<bool> marked;
  int64_t sum; int n;

  Graph(int _n = -1) {
    init(_n);
  }

  void init(int _n) {
    sum = 0; n = _n;
    adj.resize(n + 1);
    capacity.assign(n + 1, vector<int>(n + 1, 0));
    parent.assign(n + 1, -1);
    marked.assign(n + 1, false);
  }

  void addEdge(int u, int v, int cap) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    capacity[u][v] = cap;
    capacity[v][u] = 0;
  }

  bool bfs(int s, int t) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<int> Q;
    Q.push(s);

    while (not Q.empty()) {
      int cur = Q.front();
      Q.pop();

      for (auto next: adj[cur]) {
        if (parent[next] == -1 and capacity[cur][next]) {
          parent[next] = cur;
          if (next == t) return true;
          Q.push(next);
        }
      }
    }

    return false;
  }

  int64_t maxFlow(int s, int t) {
    int64_t flow = 0;
    int new_flow = 0;

    while (bfs(s, t)) {
      for (auto node: adj[t]) {
        if (parent[node] != -1 && capacity[node][t]) {
          new_flow = INF;
          parent[t] = node;
          int cur = t;
          while (cur != s) {
            new_flow = min(new_flow, capacity[parent[cur]][cur]);
            cur = parent[cur];
          }

          if (new_flow == 0) continue;
          cur = t;
          while (cur != s) {
            capacity[parent[cur]][cur] -= new_flow;
            capacity[cur][parent[cur]] += new_flow;
            cur = parent[cur];
          }
          flow += 1LL * new_flow;
        }
      }
    }
    // cout << flow << "\n";
    return flow;
  }

  /// DFS to create the cut
  void find_min_cut(int node) {
    cut_source.push_back(node);
    marked[node] = true;
    for (auto next: adj[node]) {
      if (not marked[next] and capacity[node][next]) {
        find_min_cut(next);
      }
    }
  }

  int64_t solve(int s, int t, int clothes) {
    /// Fluxul maxim din retea e cat cheltuim pe haine + outfits
    /// E limitat de sum, aka de sum(W[i]), adica profitul >= 0.
    int64_t cheltuit = maxFlow(s, t);
    int64_t profit = sum - cheltuit;

    /// Hainele care sunt in cut-ul sink-ului sunt folosite, cele accesibile din sursa nu
    /// In cazul in care nu avem profit, toate hainele ar fi in cut-ul sursei
    find_min_cut(s);

    for (int node = 1; node <= clothes; node++)
      if (not marked[node + 1])
        cut_sink.push_back(node);

    return profit;
  }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  int N, M; cin >> N >> M;
  int total_nodes = N + M + 50, s = 1, t = total_nodes;
  Graph graph(total_nodes);

  /// Source is 1, dest will be N + M + 50 (just to be sure)
  for (int i = 1; i <= N; i++) {
    int T, C; cin >> T >> C;

    /// Add paths to clothes nodes, with price as their flow
    graph.addEdge(s, i + 1, C);
  }


  for (int i = 1; i <= M; i++) {
    int node = N + i + 1, a, b, c, w;
    cin >> a >> b >> c >> w;

    /// Add a path from every piece of cloth to its outfit node with infinite cost,
    /// because it doesn't matter in the final answer with which outfit we match it,
    /// because we can match a cloth with every outfit it needs,
    /// and then add a path from outfit to our "result" with cost W(i).
    graph.addEdge(a + 1, node, INF);
    graph.addEdge(b + 1, node, INF);
    graph.addEdge(c + 1, node, INF);
    graph.addEdge(node, t, w);
    graph.sum += w;
  }

  /// Run case
  int64_t profit = graph.solve(s, t, N);
  cout << profit << " " << graph.cut_sink.size() << "\n";
  for (auto node: graph.cut_sink)
    cout << node << " ";

  return 0;
}

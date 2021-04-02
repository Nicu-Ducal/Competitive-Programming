#include <bits/stdc++.h>
using namespace std;

template <typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
using i64 = long long int;

const int INF = INT_MAX, MOD = 1e9 + 7;
const double EPS = 1e-9, PI = acos(-1);
const int dx[] = {0, 0, 0, -1, 1, -1, 1, 1, -1};
const int dy[] = {0, -1, 1, 0, 0, -1, 1, -1, 1};

/**
 *  Algorithm: Min-cost max-flow
 *  Complexity: Using only Bellman-Ford SPFA: O(|V|^2 * |E|^2)
 *              Using SPFA + Dijkstra with Johnson's Implementation: O(|V| * |E|^2 * log(|V|))
 */
struct Graph {
  struct Edge {
    int u, v, cs;

    Edge(int u, int v, int cs) : u(u), v(v), cs(cs) {}
  };

  vector<vector<int>> adj;
  vector<Edge> edges;
  vector<vector<int64_t>> capacity, cost;
  vector<bool> marked;
  vector<int> parent, ans;
  vector<int64_t> bellman_distance, new_bellman_distance, distance;
  int n;
  int64_t max_flow, mincost_maxflow;

  Graph(int _n = 0) {
    init(_n);
  }

  void init(int _n) {
    n = _n;
    adj.resize(n + 1);
    cost.assign(n + 1, vector<int64_t>(n + 1, 0));
    capacity.assign(n + 1, vector<int64_t>(n + 1, 0));
    parent.assign(n + 1, -1);
    bellman_distance.assign(n + 1, INF);
    new_bellman_distance.assign(n + 1, INF);
    distance.assign(n + 1, INF);
  }

  void addEdge(int u, int v, int cs, int cap) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    cost[u][v] = cs;
    cost[v][u] = -cs;
    capacity[u][v] = cap;
    edges.emplace_back(u, v, cs);
  }

  void complete_graph(int s, int d, int m) {
    // cout << n - m - 1 << ' ' << n - m << " " << n - 1 << "\n";
    for (int node_l = 1; node_l <= n - m - 1; node_l++)
      addEdge(s, node_l, 0, 1);
    for (int node_r = n - m; node_r <= n - 1; node_r++)
      addEdge(node_r, d, 0, 1);
  }

  void BellmanFordSPFA(int s, int d) {
    queue<int> q;
    vector<bool> in_queue(n + 1, false);
    q.push(s);
    in_queue[s] = true;
    bellman_distance[s] = 0;
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      in_queue[cur] = false;
      for (auto next: adj[cur]) {
        if (capacity[cur][next] && bellman_distance[next] > bellman_distance[cur] + cost[cur][next]) {
          bellman_distance[next] = bellman_distance[cur] + cost[cur][next];
          if (!in_queue[next]) {
            q.push(next);
            in_queue[next] = true;
          }
        }
      }
    }
  }

  /**
   * This is a modification of the original Dijkstra algorithm to eliminate the negative weights
   * The idea behind this implementation is that the distance to a node v from node u is changed to
   * mod_cost[u -> v] = cost[u -> u] + pi[v] - pi[u], where pi[x] represents the real distance from
   * the initial node to node x. In terms of minimal costs, pi can be found initially with Bellman-Ford
   * and then updated in the Dijsktra's body.
   * In my implementation:
   *    bellman_distance[x] = pi[x]
   *    new_bellman_distance[x] = The new pi for the graph after augmenting paths
   *    distance[x] = The distance to node x with mod_costs
   */
  bool JohnsonsDijkstra(int s, int d) {
    priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> pq;
    pq.push({0, s});
    distance.assign(n + 1, INF);
    new_bellman_distance.assign(n + 1, INF);
    distance[s] = 0;
    new_bellman_distance[s] = 0;

    while (!pq.empty()) {
      auto current = pq.top();
      pq.pop();

      int cur = current.second;
      int64_t cst = current.first;
      if (distance[cur] != cst) continue;

      for (auto next: adj[cur]) {
        if (capacity[cur][next]) {
          if (distance[next] > distance[cur] + cost[cur][next] + bellman_distance[cur] - bellman_distance[next]) {
            distance[next] = distance[cur] + cost[cur][next] + bellman_distance[cur] - bellman_distance[next];
            parent[next] = cur;
            new_bellman_distance[next] = new_bellman_distance[cur] + cost[cur][next];
            pq.push({distance[next], next});
          }
        }
      }
    }

    /// This is the end case. If we haven't reached the sink, then there are no more augmenting paths
    if (distance[d] == INF) return false;

    /// Else, let's compute the flow for the best path (the cost of the path will be stored into
    /// as the value of new_bellman_distance[d]
    int64_t current_flow = INF, current_cost = new_bellman_distance[d];

    int path = d;
    while (path != s) {
      current_flow = min(current_flow, capacity[parent[path]][path]);
      path = parent[path];
    }

    max_flow += current_flow;
    mincost_maxflow += current_flow * current_cost;
    path = d;
    while (path != s) {
      capacity[parent[path]][path] -= current_flow;
      capacity[path][parent[path]] += current_flow;
      path = parent[path];
    }

    /// Update the bellman_distance
    bellman_distance = new_bellman_distance;

    return true;
  }

  void min_cost_max_flow(int s, int d, int e) {
    max_flow = 0;
    mincost_maxflow = 0;
    BellmanFordSPFA(s, d);
    while (JohnsonsDijkstra(s, d));
    for (int i = 0; i < e; i++)
      if (capacity[edges[i].u][edges[i].v] != 1)
        ans.push_back(i + 1);
  }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  ifstream cin("cmcm.in");
  ofstream cout("cmcm.out");

  int N, M, E;
  cin >> N >> M >> E;
  Graph graph(N + M + 1);
  for (int i = 1; i <= E; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    graph.addEdge(u, v + N, c, 1);
  }
  graph.complete_graph(0, N + M + 1, M);

  graph.min_cost_max_flow(0, N + M + 1, E);

  cout << (int) graph.ans.size() << " " << graph.mincost_maxflow << "\n";
  for (int i = 0; i < graph.ans.size(); i++)
    cout << graph.ans[i] << " ";

  return 0;
}


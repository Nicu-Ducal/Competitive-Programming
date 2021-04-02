#include <bits/stdc++.h>
using namespace std;

template <typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
using i64 = long long int;

const int INF = INT_MAX, MOD = 1e9 + 7;
const double EPS = 1e-9, PI = acos(-1);
const int dx[] = {0, 0, 0, -1, 1, -1, 1, 1, -1};
const int dy[] = {0, -1, 1, 0, 0, -1, 1, -1, 1};

vector<int> numbers, interval, ans;

/**
 *  Algorithm: Min-cost max-flow
 *  Complexity: Using only Bellman-Ford SPFA: O(|V|^2 * |E|^2)
 *              Using SPFA + Dijkstra with Johnson's Implementation: O(|V| * |E|^2 * log(|V|))
 */
struct Graph {
  vector<vector<int>> adj;
  vector<vector<int>> capacity, cost;
  vector<bool> marked;
  vector<int> parent;
  vector<int> bellman_distance, new_bellman_distance, distance;
  int n;
  i64 max_flow, mincost_maxflow;

  Graph(int _n = 0) {
    init(_n);
  }

  void init(int _n) {
    n = _n;
    adj.resize(n + 1);
    cost.assign(n + 1, vector<int>(n + 1, 0));
    capacity.assign(n + 1, vector<int>(n + 1, 0));
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
  i64 JohnsonsDijkstra(int s, int d, int k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    distance.assign(n + 1, INF);
    new_bellman_distance.assign(n + 1, INF);
    distance[s] = 0;
    new_bellman_distance[s] = 0;

    while (!pq.empty()) {
      auto current = pq.top();
      pq.pop();

      int cur = current.second;
      i64 cst = current.first;
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
    if (distance[d] == INF) return 0LL;

    /// Else, let's compute the flow for the best path (the cost of the path will be stored into
    /// as the value of new_bellman_distance[d]
    i64 current_flow = k, current_cost = new_bellman_distance[d];

    int path = d;
    while (path != s) {
      current_flow = min(current_flow, 1LL * capacity[parent[path]][path]);
      path = parent[path];
    }

    max_flow += current_flow;
    mincost_maxflow += 1LL * current_flow * current_cost;
    path = d;
    while (path != s) {
      capacity[parent[path]][path] -= current_flow;
      capacity[path][parent[path]] += current_flow;
      path = parent[path];
    }

    /// Update the bellman_distance
    bellman_distance = new_bellman_distance;

    return current_flow;
  }

  void min_cost_max_flow(int s, int d) {
    max_flow = 0;
    mincost_maxflow = 0;
    BellmanFordSPFA(s, d);
    while (JohnsonsDijkstra(s, d, INF));
  }

  int min_cost_flow(int s, int d, int k) {
    i64 kflow = 0;
    mincost_maxflow = 0;
    BellmanFordSPFA(s, d);
    while (kflow < k) {
      kflow += JohnsonsDijkstra(s, d, k - kflow);
    }
    return mincost_maxflow;
  }

  void remake_solution(int s, int n) {
    for (int i = 1; i <= n; i++) {
      bool same = true;
      for (auto next: adj[i]) {
        if (next == s) continue;
        same &= (capacity[i][next] == 1);
        //cout << numbers[i] << " " << interval[next] << " " << next  << " " << capacity[i][next] << "\n";
        if (not same) {
          ans.push_back(interval[next]);
          break;
        }
      }
      if (same)
        ans.push_back(numbers[i]);
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  ifstream cin("smen.in");
  ofstream cout("smen.out");

  int n, k, a, b;
  cin >> n >> k >> a >> b;

  const int MAX_NODES = 1005;
  int s = 1000, t = 1001;
  Graph graph(MAX_NODES);

  numbers.assign(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> numbers[i];

    /// Starting numbers wiil be the first layer nodes
    graph.addEdge(s, i, 0, 1);
  }

  int sz_int = n + 1 + b - a + 1;
  int cur = a;
  interval.assign(sz_int, 0);
  for (int i = n + 1; i < sz_int; i++) {
    interval[i] = cur++;

    /// Wanted numbers will be the second layer nodes, with cost equal to how many operations we have
    /// to do on the current number to obtain this resulting number. Flow is 1.
    for (int j = 1; j <= n; j++)
      graph.addEdge(j, i, abs(interval[i] - numbers[j]), 1);

    graph.addEdge(i, t, 0, 1);
  }

//  cout << interval << "\n";
  cout << graph.min_cost_flow(s, t, k) << "\n";
  graph.remake_solution(s, n);
  for (auto num: ans)
    cout << num << " ";

  return 0;
}

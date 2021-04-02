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
 * Flow with Edmonds-Karp
 * Idea: Fix the source node (which will be in one room) and iterate through the rest of nodes to
 * and set it to sink. Fixed node and the sink will always be in two different cut sets. Find the minimum
 * max_flow possible, because we need the min_cut to be minimal (i.e. to have more croco-babies in the sets).
 * We can fix only one source, because the nodes in the cut of the fixed source will return the same result
 * as the fixed one. Or another explanation is: the best cut will always be found, because even if the cut with the sink
 * node has only one node T (i.e. the destination), that node will be of course visited if we choose the our source
 * node to be any of the the remaining ones (in the source cut), and it'll yield the same answer, because the graph is
 * undirected.
 */
struct Graph {
  vector<vector<int>> adj, capacity, croco;
  vector<int> parent, cut;
  vector<bool> marked;
  int sum, n;

  Graph(int _n = -1) {
    init(_n);
  }

  void init(int _n) {
    sum = 0; n = _n;
    adj.resize(n + 1);
    capacity.resize(n + 1, vector<int>(n + 1, 0));
    parent.resize(n + 1);
    marked.resize(n + 1, false);
    croco.resize(n + 1, vector<int>(n + 1, 0));
  }

  void addEdge(int u, int v, int cap) {
    adj[u].push_back(v);
    capacity[u][v] = cap;
  }

  int bfs(int s, int t) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> Q;
    Q.push({s, INF});

    while (not Q.empty()) {
      int cur = Q.front().first;
      int flow = Q.front().second;
      Q.pop();

      for (auto nxt: adj[cur]) {
        if (parent[nxt] == -1 and capacity[cur][nxt]) {
          parent[nxt] = cur;
          int new_flow = min(flow, capacity[cur][nxt]);
          if (nxt == t) return new_flow;
          Q.push({nxt, new_flow});
        }
      }
    }

    return 0;
  }

  int maxFlow(int s, int t) {
    int flow = 0;
    int new_flow;
    /// Restore the original graph
    capacity = croco;

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
          flow += new_flow;
        }
      }
    }

    return flow;
  }

  /// DFS to create the cut
  void find_min_cut(int node) {
    cut.push_back(node);
    marked[node] = true;
    for (auto next: adj[node]) {
      if (not marked[next] and capacity[node][next]) {
        find_min_cut(next);
      }
    }
  }

  /// Finds the best min_cut and returns the value of croco children (flow_sum - min_cut)
  int croco_chan() {
    /// Fix the source to be s = 1, iterate over possible sinks
    /// Another way is to iterate over sources with a fixed sink
    int s = 1, t;
    int min_max_flow = INF, ans_dest;
    for (int dest = 2; dest <= n; dest++) {
      t = dest;
      int fuckfuck = maxFlow(s, t);
      if (fuckfuck < min_max_flow) {
        min_max_flow = fuckfuck;
        ans_dest = dest;
      }
    }

    /// As we have the answer, lets make the cut
    maxFlow(s, ans_dest);
    find_min_cut(s);

    return sum - min_max_flow;
  }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  ifstream cin("croco.in");
  ofstream cout("croco.out");

  int n; cin >> n;
  Graph graph(n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> graph.croco[i][j];
      if (graph.croco[i][j]) {
        graph.addEdge(i, j, graph.croco[i][j]);
        if (i < j) graph.sum += graph.croco[i][j];
      }
    }
  }

  int ibati = graph.croco_chan();
  cout << ibati << " " << graph.cut.size() << "\n";
  for (auto node: graph.cut)
    cout << node << " ";

  return 0;
}
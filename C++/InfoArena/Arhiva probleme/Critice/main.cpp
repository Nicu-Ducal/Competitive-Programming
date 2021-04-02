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
  struct Edge {
    int u, v, cap;

    Edge(int u, int v, int cap) : u(u), v(v), cap(cap) {}
  };

  vector<Edge> edges;
  vector<vector<int>> adj, capacity;
  vector<int> parent, marked, ans;
  int n;

  Graph(int _n = -1) {
    init(_n);
  }

  void init(int _n) {
    n = _n;
    adj.resize(n + 1);
    capacity.resize(n + 1, vector<int>(n + 1, 0));
    parent.resize(n + 1);
    marked.assign(n + 1, false);
  }

  void addEdge(int u, int v, int cap) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    capacity[u][v] = cap;
    capacity[v][u] = cap;
  }

  int bfs(int s, int t) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<int> Q;
    Q.push(s);

    while (not Q.empty()) {
      int cur = Q.front();
      Q.pop();

      for (auto nxt: adj[cur]) {
        if (parent[nxt] == -1 and capacity[cur][nxt]) {
          parent[nxt] = cur;
          if (nxt == t) return true;
          Q.push(nxt);
        }
      }
    }

    return false;
  }

  int maxFlow(int s, int t) {
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

    return flow;
  }

  /// Create the min-cut set with the source
  void dfs(int node) {
    marked[node] = true;
    for (auto next: adj[node]) {
      if (not marked[next] and capacity[node][next])
        dfs(next);
    }
  }

  /// Idea: Compute the maximum flow in the network. After that, we have to find the min-cut
  /// edges. First we make the cut-set with the source and then find all the edges that have
  /// capacity 0 and two nodes in different sets
  void solve(int s, int t) {
    int flow = maxFlow(s, t);

    /// Compute min-cut set with source
    dfs(s);
    for (int i = 0; i < (int) edges.size(); i++) {
      if ((marked[edges[i].u] and not marked[edges[i].v] and capacity[edges[i].u][edges[i].v] == 0)
        or (marked[edges[i].v] and not marked[edges[i].u] and capacity[edges[i].v][edges[i].u] == 0))
        ans.push_back(i + 1);
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  
  ifstream cin("critice.in");
  ofstream cout("critice.out");
  
  int n, m;
  cin >> n >> m;
  Graph graph(n);
  for (int i = 1; i <= m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    graph.addEdge(u, v, c);
    graph.edges.emplace_back(u, v, c);
  }

  graph.solve(1, n);
  cout << graph.ans.size() << "\n";
  for (auto node: graph.ans)
    cout << node << "\n";

  return 0;
}

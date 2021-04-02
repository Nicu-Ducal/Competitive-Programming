#include <bits/stdc++.h>
using namespace std;

template <typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
using i64 = long long int;

const int INF = INT_MAX, MOD = 1e9 + 7;
const double EPS = 1e-9, PI = acos(-1);
const int dx[] = {0, 0, 0, -1, 1, -1, 1, 1, -1};
const int dy[] = {0, -1, 1, 0, 0, -1, 1, -1, 1};

/*
 * Algorithm: Dinic's Algorithm (Complexity: O(|V|^2 * |E|)
 */
struct FlowEdge {
  long long u, v;
  long long cap, flow = 0;

  FlowEdge(long long u, long long v, long long cap) : v(v), u(u), cap(cap) {}
};

struct Graph {
  const long long INF_FLOW = 1e18;
  vector<FlowEdge> edges;
  vector<vector<int>> adj, croco;
  long long n, m = 0;
  long s, t;
  vector<int> level, ptr, cut;
  vector<bool> marked;
  queue<int> q;

  Graph(int _n = 0) {
    init(_n);
  }

  void init(int _n) {
    n = _n;
    s = 1, t = n;
    adj.resize(n + 1);
    level.resize(n + 1, 0);
    ptr.resize(n + 1, 0);
    marked.resize(n + 1, false);
  }

  void addEdge(int u, int v, long long c) {
    edges.emplace_back(u, v, c);
    edges.emplace_back(v, u, 0);
    adj[u].push_back(m);
    adj[v].push_back(m + 1);
    m += 2;
  }

  bool bfs() {
    while (not q.empty()) {
      int u = q.front();
      q.pop();
      for (auto idx: adj[u]) {
        if (edges[idx].cap - edges[idx].flow < 1 or level[edges[idx].v] != -1) continue;
        level[edges[idx].v] = level[u] + 1;
        q.push(edges[idx].v);
      }
    }
    return (level[t] != -1);
  }

  long long dfs(int u, long long pushed) {
    if (pushed == 0) return 0;
    if (u == t) return pushed;
    for (int &cid = ptr[u]; cid < (int) adj[u].size(); cid++) {
      int idx = adj[u][cid];
      int v = edges[idx].v;
      if (level[u] + 1 != level[v] or edges[idx].cap - edges[idx].flow < 1) continue;
      long long tr = dfs(v, min(pushed, edges[idx].cap - edges[idx].flow));
      if (tr == 0) continue;
      edges[idx].flow += tr;
      edges[idx ^ 1].flow -= tr;
      return tr;
    }
    return 0;
  }

  long long flow() {
    long long fw = 0;
    while (true) {
      fill(level.begin(), level.end(), -1);
      level[s] = 0;
      q.push(s);
      if (not bfs()) break;
      fill(ptr.begin(), ptr.end(), 0);
      while (long long pushed = dfs(s, INF_FLOW))
        fw += pushed;
    }
    return fw;
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
    int s = 1;
    int min_max_flow = INF, ans_dest;
    for (int dest = 2; dest <= n; dest++) {
      int fuckfuck = maxFlow(s, dest);
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

//  ifstream cin("croco.in");
//  ofstream cout("croco.out");

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

  cout << graph.croco_chan() << " " << graph.cut.size() << "\n";
  for (auto node: graph.cut)
    cout << node << " ";

  return 0;
}


#include <bits/stdc++.h>
using namespace std;

template <typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
using i64 = long long int;

const int INF = INT_MAX, MOD = 1e9 + 7;
const double EPS = 1e-9, PI = acos(-1);
const int dx[] = {0, 0, 0, -1, 1, -1, 1, 1, -1};
const int dy[] = {0, -1, 1, 0, 0, -1, 1, -1, 1};

const int MAX_N = 20010;

/*
 * Algorithm: Dinic's Algorithm (Complexity: O(|V|^2 * |E|)
 */
struct FlowEdge {
  int u, v;
  int cap, flow = 0;

  FlowEdge(int u, int v, int cap) : v(v), u(u), cap(cap) {}
};

struct Graph {
  const int INF_FLOW = 1e9;
  vector<FlowEdge> edges;
  vector<vector<int>> adj;
  int n, m = 0;
  int s, t;
  vector<int> level, ptr;
  queue<int> q;
  vector<pair<int, int>> ans;

  Graph(int _n = 0) {
    init(_n);
  }

  void init(int _n) {
    n = _n;
    s = 1, t = n;
    adj.resize(n + 1);
    level.resize(n + 1, 0);
    ptr.resize(n + 1, 0);
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

  int dfs(int u, int pushed) {
    if (pushed == 0) return 0;
    if (u == t) return pushed;
    for (int &cid = ptr[u]; cid < (int) adj[u].size(); cid++) {
      int idx = adj[u][cid];
      int v = edges[idx].v;
      if (level[u] + 1 != level[v] or edges[idx].cap - edges[idx].flow < 1) continue;
      int tr = dfs(v, min(pushed, edges[idx].cap - edges[idx].flow));
      if (tr == 0) continue;
      edges[idx].flow += tr;
      edges[idx ^ 1].flow -= tr;
      return tr;
    }
    return 0;
  }

  int flow() {
    int fw = 0;
    while (true) {
      fill(level.begin(), level.end(), -1);
      level[s] = 0;
      q.push(s);
      if (not bfs()) break;
      fill(ptr.begin(), ptr.end(), 0);
      while (int pushed = dfs(s, INF_FLOW))
        fw += pushed;
    }
    return fw;
  }

  i64 solve_matching(int _s, int _t, int n1, int n2) {
    s = _s, t = _t;
    i64 matching = flow();
    for (int i = 1; i <= n1; i++) {
      for (auto idx: adj[i]) {
        if (edges[idx].v == s) continue;
        if (edges[idx].flow == 1) {
          ans.emplace_back(i, edges[idx].v - n1);
          break;
        }
      }
    }
    return matching;
  }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  ifstream cin("cuplaj.in");
  ofstream cout("cuplaj.out");

  int N1, N2, M, s = 0, t = MAX_N;
  Graph graph(MAX_N + 1);
  cin >> N1 >> N2 >> M;
  for (int i = 1; i <= N1; i++) {
    graph.addEdge(s, i, 1);
  }
  for (int i = N1 + 1; i <= N1 + N2; i++) {
    graph.addEdge(i, t, 1);
  }
  for (int i = 1; i <= M; i++) {
    int u, v; cin >> u >> v;
    v += N1;
    graph.addEdge(u, v, 1);
  }

  cout << graph.solve_matching(s, t, N1, N2) << "\n";
  for (auto pr: graph.ans)
    cout << pr.first << " " << pr.second << "\n";

  return 0;
}

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
  vector<pair<int, int>> edges;
  vector<int> parent;
  vector<bool> marked;
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
    capacity[v][u] = 0;
  }

  void make_bipartite(int N) {
    for (int i = 1; i <= N; i++)
      for (int j = N + 1; j <= 2 * N; j++)
        if (i != j - N)
          addEdge(i, j, 1);
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

  void solve(int S, int D, int N) {
    for (int node = 1; node <= N; node++) {
      for (auto next: adj[node]) {
        if (next != S and capacity[node][next] == 0)
          edges.emplace_back(node, next - N);
      }
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  ifstream cin("harta.in");
  ofstream cout("harta.out");
  
  int N; cin >> N;
  Graph graph(2 * N + 1);
  int S = 0, D = 2 * N + 1;

  graph.make_bipartite(N);
  for (int i = 1; i <= N; i++) {
    int in, out; cin >> in >> out;
    graph.addEdge(S, i, in);
    graph.addEdge(i + N, D, out);
  }

  graph.solve(S, D, N);
  cout << graph.edges.size() << "\n";
  for (auto edge: graph.edges)
    cout << edge.first << " " << edge.second << "\n";

  return 0;
}

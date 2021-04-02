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
/// Algorithm: Kuhn's algorithm for bipartite matchings (O(NM) or O(N^3) worst case)
/// Hopcroft-Karp's algorithm for bipartite marchings (O(sqrt(N) * M))
struct Graph {
  vector<vector<int>> adj;
  vector<bool> marked;
  vector<int> parent, level, match, is_matched;
  int n, n1, n2, match_num = 0;

  Graph(int _n1 = 0, int _n2 = 0) {
    init(_n1, _n2);
  }

  void init(int _n1, int _n2) {
    n = _n1 + _n2;
    n1 = _n1, n2 = _n2;
    adj.resize(n1 + 1);
    marked.resize(n1 + 1, false);
    match.resize(n2 + 1, -1);
    is_matched.resize(n1 + 1, -1);
  }

  void addEdge(int u, int v) {
    adj[u].push_back(v);
    // adj[v].push_back(u);
  }

  bool KuhnDFS(int node) {
    if (marked[node]) return false;
    marked[node] = true;
    for (auto next: adj[node]) {
      if (match[next] == -1 or KuhnDFS(match[next])) {
        match[next] = node;
        return true;
      }
    }
    return false;
  }

  /// Really, is this TLE???
  void Kuhn() {
    /// Adding the arbitrary matching heuristic
    vector<bool> arbitrary_matched(n1 + 1, false);
    for (int node = 1; node <= n1; node++) {
      for (auto next: adj[node]) {
        if (match[next] == -1) {
          match_num++;
          match[next] = node;
          arbitrary_matched[node] = true;
          break;
        }
      }
    }

    for (int node = 1; node <= n1; node++) {
      if (arbitrary_matched[node]) continue;
      marked.assign(n1 + 1, false);
      if (KuhnDFS(node))
        match_num++;
    }
  };

  /// Hopcroft-Karp Algorithm (O(sqrt(N) * M))
  bool HopcroftKarpDFS(int node) {
    if (marked[node]) return false;
    marked[node] = true;
    for (auto next: adj[node]) {
      if (match[next] == -1 or HopcroftKarpDFS(match[next])) {
        is_matched[node] = next;
        match[next] = node;
        return true;
      }
    }
    return false;
  }

  /// Uses the same DFS approach as Kuhn, I think
  void HopcroftKarp() {
    bool good = true;
    while (good) {
      good = false;
      marked.assign(n1 + 1, false);
      for (int node = 1; node <= n1; node++) {
        if (is_matched[node] == -1) {
          good |= HopcroftKarpDFS(node);
        }
      }
    }

    for (int node = 1; node <= n2; node++) {
      if (match[node] != -1)
        match_num++;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  ifstream cin("cuplaj.in");
  ofstream cout("cuplaj.out");
  
  int N1, N2, M;
  cin >> N1 >> N2 >> M;
  Graph graph(N1, N2);
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    graph.addEdge(u, v);
  }

  /// graph.Kuhn();
  graph.HopcroftKarp();

  cout << graph.match_num << "\n";
  for (int i = 1; i <= N2; i++) {
    if (graph.match[i] != -1) {
      cout << graph.match[i] << " " << i << "\n";
    }
  }

  return 0;
}

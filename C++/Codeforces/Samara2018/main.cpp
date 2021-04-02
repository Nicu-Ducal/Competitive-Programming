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
/// Hopcroft-Karp's algorithm for bipartite matchings (O(sqrt(N) * M))
struct Graph {
  vector<vector<int>> adj, initial;
  vector<bool> marked, left_set, right_set, bad;
  vector<int> parent, level, match, is_matched;
  vector<pair<int, int>> ans;
  int n, n1, n2, match_num = 0;

  Graph(int _n1 = 0, int _n2 = 0) {
    init(_n1, _n2);
  }

  void init(int _n1, int _n2) {
    n = _n1 + _n2;
    n1 = _n1, n2 = _n2;
    adj.resize(n1 + 1);
    initial.resize(n1 + 1);
    marked.resize(n1 + 1, false);
    match.resize(n2 + 1, -1);
    is_matched.resize(n1 + 1, -1);
    left_set.assign(n1 + 1, false);
    right_set.assign(n1 + 1, false);
  }

  void add_initial_edge(int u, int v) {
    initial[u].push_back(v);
  }

  void add_bipartite_edge(int u, int v) {
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

  /// Find the bipartite edges
  void dfs(int node) {
    marked[node] = true;
    for (auto next: initial[node])
      if (not marked[next])
        dfs(next);
  }

  int compute_bipartite_edges(int k) {
    bad.assign(n1 + 1, false);
    int matchings = k;
    for (int i = 1; i <= n1; i++) {
      if (left_set[i] == right_set[i] and left_set[i] == 1)
        bad[i] = true, --matchings;
    }

    for (int node = 1; node <= n1; node++) {
      if (left_set[node] and not bad[node]) {
        marked.assign(n1 + 1, false);
        dfs(node);
        for (int next = 1; next <= n1; next++)
          if (marked[next] and not bad[next] and right_set[next])
            add_bipartite_edge(node, next);
      }
    }
    return matchings;
  }

  // Pentru mine
  void afis() {
    for (int i = 1; i <= n1; i++) {
      cout << i << ": ";
      for (auto next: adj[i]) cout << next << ' ';
      cout << '\n';
    }
  }

  bool path_dfs(int start, int end, vector<pair<int,int>>& path) {
    if (start == end)
      return true;
    marked[start] = true;
    /// Trebuie sa caut un path din start pana in end, si sa fie bun
    /// Pe acest path o sa pot face transferul
    for (auto next: initial[start]) {
      if (not marked[next]) {
        bool good = path_dfs(next, end, path);
        if (good) {
          path.emplace_back(start, next);
          if (left_set[start]) {
            reverse(path.begin(), path.end());
            while (path.size()) {
              auto transf = path.back();
              path.pop_back();
              ans.push_back(transf);
            }
          }
          return true;
        }
      }
    }

    return false;
  }

  bool remake_answer() {
    for (int rg = 1; rg <= n1; rg++) {
      if (right_set[rg]) {
        vector<pair<int, int>> path;
        marked.assign(n1 + 1, false);
        int lf = match[rg];
        path_dfs(lf, rg, path);
        left_set[lf] = false;
        left_set[rg] = true;
      }
    }
    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  int N, K; cin >> N >> K;
  Graph graph(N, N);
  for (int i = 1; i <= K; i++) {
    int p; cin >> p;
    graph.left_set[p] = true;
  }
  for (int i = 1; i <= K; i++) {
    int p; cin >> p;
    graph.right_set[p] = true;
  }
  for (int u = 1; u <= N; u++) {
    string fuck; cin >> fuck;
    for (int v = 0; v < N; v++) {
      if (fuck[v] == '1')
        graph.add_initial_edge(u, v + 1);
    }
  }

  /// Fac mai intai bipartit
  int matchings = graph.compute_bipartite_edges(K);

  /// Dupa asta Hopcroft sau Kuhn
  graph.HopcroftKarp();

  /// Daca match == k deci e bun, nu - nu
  if (matchings != graph.match_num) {
    //cout << matchings << " " << graph.match_num << "\n";
    cout << "NO\n";
    return 0;
  }

  if (graph.remake_answer()) {
    cout << "YES\n" << graph.ans.size() << "\n";
    reverse(graph.ans.begin(), graph.ans.end());
    for (auto tsf: graph.ans)
      cout << tsf.first << " " << tsf.second << '\n';
  } else {
    cout << "NO\n";
  }

  return 0;
}
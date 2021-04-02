#include <bits/stdc++.h>
using namespace std;

template <typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
using i64 = long long int;

const int INF = INT_MAX, MOD = 1e9 + 7;
const double EPS = 1e-9, PI = acos(-1);
const int dx[] = {0, 0, 0, -1, 1, -1, 1, 1, -1};
const int dy[] = {0, -1, 1, 0, 0, -1, 1, -1, 1};

struct Edge {
  int to, l, r;

  Edge(int to, int l, int r) : to(to), l(l), r(r) {}
};

/// Weighted graph
struct Graph {
  vector<vector<Edge>> adj;
  vector<bool> marked;
  vector<int> parent, level, lefts, rights;
  int n;

  Graph(int _n = 0) {
    init(_n);
  }

  void init(int _n) {
    n = _n;
    adj.resize(n + 1);
    marked.assign(n + 1, false);
  }

  void addEdge(int u, int v, int l, int r) {
    adj[u].push_back({v, l, r});
    adj[v].push_back({u, l, r});
    lefts.push_back(l);
    rights.push_back(r);
  }

  bool BFS(int start, int end, int l, int r) {
    queue<int> q;
    q.emplace(start);
    marked.assign(n + 1, false);
    while (not q.empty()) {
      int node = q.front(); q.pop();
      marked[node] = true;
      for (auto next: adj[node])
        if (not marked[next.to])
          if (next.l <= l and l <= r and r <= next.r) {
            q.push(next.to);
            if (next.to == end)
              return true;
          }
    }
    return false;
  }

  /// Mode: 1 for max, 0 for min
  int binary_search(int lf) {
    int M = (int) rights.size();
    int lo = 0, hi = M;
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (BFS(1, n, lf, rights[mid])) {
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }
    return lo - 1;
  }

  int solve() {
    /// Idea: Maybe fix a left point and then binary search on the right and check if it is good?
    sort(lefts.begin(), lefts.end());
    sort(rights.begin(), rights.end());

    int M = (int) rights.size();
    int ans = -1;
    for (auto lf: lefts) {
      if (lf > rights[M - 1]) break;
      int rg = binary_search(lf);
      if (rg != -1 and BFS(1, n, lf, rights[rg])) {
        ans = max(ans, rights[rg] - lf + 1);
        // cout << rights[rg] << " " << lf << "\n";
      }
    }
    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  int N, M;
  cin >> N >> M;
  Graph graph(N);
  for (int i = 1; i <= M; i++) {
    int u, v, l, r;
    cin >> u >> v >> l >> r;
    graph.addEdge(u, v, l, r);
  }

  int ans = graph.solve();
  if (ans == -1) cout << "Nice work, Dima!\n";
  else cout << ans << "\n";

  return 0;
}

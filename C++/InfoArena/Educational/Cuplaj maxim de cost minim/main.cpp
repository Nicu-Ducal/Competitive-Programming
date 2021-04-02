#include <bits/stdc++.h>
using namespace std;

template <typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
using i64 = long long int;

const int INF = INT_MAX, MOD = 1e9 + 7;
const double EPS = 1e-9, PI = acos(-1);
const int dx[] = {0, 0, 0, -1, 1, -1, 1, 1, -1};
const int dy[] = {0, -1, 1, 0, 0, -1, 1, -1, 1};

vector<int> edges;

/// Algorithm: Hungarian Algorithm
/// Complexity: O(N^3)
namespace Hungarian {
  vector<vector<int>> table;
  vector<int> assignment;

  void init(int n, int m) {
    table.assign(n, vector<int>(m));
  }

  int64_t match() {
    int64_t n = (int) table.size();
    int64_t m = (n != 0 ? (int) table[0].size() : 0);

    vector<int64_t> u(n + 1), v(m + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  int N, K, M;
  cin >> N >> K >> M;

  edges.assign(M + 1, 0);
  bool to_swap = (N > K);
  if (to_swap) swap(N, K);
  Hungarian::init(N, K);
  for (int i = 1; i <= M; i++) {
    int u, v, c;
    if (to_swap) swap(u, v);
    cin >> u >> v >> c;
    edges[i] = c;
    Hungarian::table[u - 1][v - 1] = i;
  }



  return 0;
}

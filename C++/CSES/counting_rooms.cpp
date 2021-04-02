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
struct Lee {
  vector<vector<int>> adj;
  vector<vector<bool>> marked;
  int n, m;

  Lee(int _n, int _m) {
    init(_n, _m);
  }

  void init(int _n, int _m) {
    n = _n, m = _m;
    adj.resize(n, vector<int>(m, 0));
    marked.resize(n, vector<bool>(m, false));
  }

  int compute_rooms() {
    int ans = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (not marked[i][j] and adj[i][j] == 1) {
          q.emplace(i, j);
          marked[i][j] = true;
          while (not q.empty()) {
            int x = q.front().first, y = q.front().second; q.pop();
            for (int k = 1; k <= 4; k++) {
              if (x + dx[k] >= 0 and x + dx[k] < n and y + dy[k] >= 0 and y + dy[k] < m
                and not marked[x + dx[k]][y + dy[k]] and adj[x + dx[k]][y + dy[k]] == 1) {
                q.emplace(x + dx[k], y + dy[k]);
                marked[x + dx[k]][y + dy[k]] = true;
              }
            }
          }
          ans++;
        }

    return ans;
  }

};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  int n, m; cin >> n >> m;
  Lee lee(n, m);
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    for (int j = 0; j < (int) s.size(); j++) {
      if (s[j] == '#') lee.adj[i][j] = 0;
      else lee.adj[i][j] = 1;
    }
  }

  cout << lee.compute_rooms() << "\n";

  return 0;
}


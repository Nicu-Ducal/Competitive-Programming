#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

template <typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
using i64 = long long int;

const int INF = INT_MAX, MOD = 1e9 + 7;
const double EPS = 1e-9, PI = acos(-1);
const int dx[] = {0, 0, 0, -1, 1, -1, 1, 1, -1};
const int dy[] = {0, -1, 1, 0, 0, -1, 1, -1, 1};

/// Undirected/directed graph (for directed delete a push_back from the addEdge
struct Lee {
  vector<vector<int>> adj, dist;
  vector<vector<char>> way;
  vector<vector<pair<int, int>>> parent;
  int n, m;
  pair<int, int> start, end;

  Lee(int _n, int _m) {
    init(_n, _m);
  }

  void init(int _n, int _m) {
    n = _n, m = _m;
    adj.resize(n, vector<int>(m, 0));
    way.resize(n, vector<char>(m, 0));
    dist.resize(n, vector<int>(m, 0));
    parent.resize(n, vector<pair<int, int>>(m, {-1, -1}));
  }

  void compute_labyrinth() {
    bool good = false;
    queue<pair<int, int>> q;
    q.emplace(start);
    way[start.x][start.y] = 'A';
    while (not q.empty()) {
      int x = q.front().x, y = q.front().y; q.pop();
      if (adj[x][y] == 3) {
        good = true;
        break;
      }
      for (int k = 1; k <= 4; k++) {
        int next_x = x + dx[k], next_y = y + dy[k];
        if (next_x >= 0 and next_x < n and next_y >= 0 and next_y < m
            and way[next_x][next_y] == 0 and adj[next_x][next_y] > 0) {
          q.emplace(next_x, next_y);
          switch(k) {
            case 1:
              way[next_x][next_y] = 'L';
              break;
            case 2:
              way[next_x][next_y] = 'R';
              break;
            case 3:
              way[next_x][next_y] = 'U';
              break;
            case 4:
              way[next_x][next_y] = 'D';
          }
          dist[next_x][next_y] = dist[x][y] + 1;
          parent[next_x][next_y] = {x, y};
        }
      }
    }

    if (not good)
      cout << "NO\n";
    else {
      cout << "YES\n" << dist[end.x][end.y] << "\n";
      vector<char> ans;
      for (auto node = end; node != start; node = parent[node.x][node.y])
        ans.push_back(way[node.x][node.y]);
      reverse(ans.begin(), ans.end());
      for (auto x: ans)
        cout << x;
    }
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
      else if (s[j] == 'A') lee.start = {i, j}, lee.adj[i][j] = 2;
      else if (s[j] == 'B') lee.end = {i, j}, lee.adj[i][j] = 3;
      else lee.adj[i][j] = 1;
    }
  }

  lee.compute_labyrinth();

  return 0;
}


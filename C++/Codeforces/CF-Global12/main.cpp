#include <bits/stdc++.h>
using namespace std;

template <typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
using i64 = long long int;

const int INF = INT_MAX, MOD = 1e9 + 7;
const double EPS = 1e-9, PI = acos(-1);
const int dx[] = {0, 0, 0, -1, 1, -1, 1, 1, -1};
const int dy[] = {0, -1, 1, 0, 0, -1, 1, -1, 1};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int k = 0;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
      cin >> grid[i];
      for (int j = 0; j < n; j++)
        if (grid[i][j] != '.') k++;
    }
    int pos = 2;
    for (int i = 0; i < n; i++) {
      int nextpos = (pos == 0) ? ((pos + 3) % n - 1) : (pos - 1);
      for (int j = pos; j < n; j += 3) {
        if (grid[i][j] == 'X') grid[i][j] = 'O';
      }
      pos = nextpos;
    }

    for (int i = 0; i < n; i++) {
      cout << grid[i] << "\n";
    }
  }

  return 0;
}
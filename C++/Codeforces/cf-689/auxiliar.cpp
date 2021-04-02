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

  int tests; cin >> tests;
  while (tests--) {
    int64_t n, m; cin >> n >> m;
    vector<string> s(n);
    vector<vector<int64_t>> dp(n, vector<int64_t>(m, 0));
    for (int64_t i = 0; i < n; i++) {
      cin >> s[i];
      for (int64_t j = 0; j < m; j++)
        if (s[i][j] == '*')
          ++dp[i][j];
    }
    int64_t ans = 0;
    for (int64_t k = 2; k <= n; k++) {
      for (int64_t i = 0; i < n - 1; i++) {
        for (int64_t j = k - 1; j <= m - k + 1; j++) {
          if (dp[i][j] == k - 1 && dp[i + 1][j] == k - 1 && dp[i + 1][j - 1] == k - 1 && dp[i + 1][j + 1] == k - 1)
            dp[i][j] = k;
        }
      }
    }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        ans += dp[i][j];

    cout << ans << "\n";

  return 0;
}

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
    int n; cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
      if (i + s[i] > n) {
        int new_s = n - i;
        ans += (s[i] - new_s) * 1LL;
        s[i] = new_s;
      }

      while (s[i] != 1) {
        int j = i;
        while (j < n) {
          int new_j = s[j] + j;
          s[j] = max(s[j] - 1, 1);
          j = new_j;
        }
        ans++;
      }
    }
    cout << ans << "\n";
  }

  return 0;
}


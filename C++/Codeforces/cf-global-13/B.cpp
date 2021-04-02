#include <bits/stdc++.h>
using namespace std;

template <typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
using i64 = long long int;

const int INF = INT_MAX, MOD = 1e9 + 7;
const double EPS = 1e-9, PI = acos(-1);
const int dx[] = {0, 0, 0, -1, 1, -1, 1, 1, -1};
const int dy[] = {0, -1, 1, 0, 0, -1, 1, -1, 1};

const int COLS = 1e6 + 2;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  int tests; cin >> tests;
  while (tests--) {
    int n, u, v;
    cin >> n >> u >> v;
    vector<int> a(n + 1);
    int same = -1, good = true;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (i == 1) same = a[i];
      if (same != a[i]) good = false;
    }
    if (good) {
      cout << min(u + v, 2 * v) << "\n";
    } else {
      bool ok = false;
      for (int i = 1; i < n; i++)
        if (abs(a[i + 1] - a[i]) >= 2)
          ok = true;
      if (ok)
        cout << 0 << "\n";
      else
        cout << min(u, v) << "\n";
    }
  }

  return 0;
}

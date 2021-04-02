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
    int64_t x; cin >> x;
    bool ok = false;
    for (int64_t a = 1; a <= 1e4 * 1LL; a++) {
      int64_t to_check = x - a * a * a;
      if (to_check <= 0) break;
      int64_t lf = a, rg = 10000LL;
      while (lf < rg) {
        int64_t mid = lf + (rg - lf) / 2;
        //printf("%d ", mid);
        if (mid * mid * mid <= to_check)
          lf = mid + 1;
        else
          rg = mid;
      }
      lf--;
      if (lf * lf * lf == to_check) {
        ok = true;
        break;
      }
    }
    if (ok) cout << "Yes\n";
    else cout << "No\n";
  }

  return 0;
}


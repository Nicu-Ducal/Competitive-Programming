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

  i64 t = 200, n;
  vector<i64> a;
  while (t--) {
    cin >> n;
    a.push_back(n);
  }
  sort(a.begin(), a.end());
  i64 ans = 1;
  for (i64 p1 = 0; p1 < (i64) a.size() - 2; p1++) {
    i64 p2 = p1 + 1, p3 = (i64) a.size() - 1;
    while (p2 < p3) {
      if (a[p2] + a[p3] < 2020 - a[p1]) ++p2;
      else if (a[p2] + a[p3] > 2020 - a[p1]) --p3;
      else {
        printf("%d %d %d\n", a[p1], a[p2], a[p3]);
        ans = a[p1] * a[p2] * a[p3];
        ++p2, --p3;
      }
    }
  }
  cout << ans << "\n";

  return 0;
}
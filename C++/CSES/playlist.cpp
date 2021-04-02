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

  int n; cin >> n;
  vector<int64_t> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  map<int64_t, int> umap;
  int ans = 1, l = 0;
  umap[a[l]] = l;
  for (int r = 1; r < n; r++) {
    if (umap.find(a[r]) == umap.end() or umap[a[r]] < l) {
      umap[a[r]] = r;
      ans = max(ans, r - l + 1);
    } else {
      l = umap[a[r]] + 1;
      umap[a[r]] = r;
    }
  }
  cout << ans << '\n';

  return 0;
}

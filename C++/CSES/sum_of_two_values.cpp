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

  map<int, int> us;
  int n, sum; cin >> n >> sum;
  vector<int> a(n);
  bool good = false;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (not good) {
      int targ = sum - a[i];
      if (us.find(targ) != us.end()) {
        cout << us[targ] + 1 << ' ' << i + 1 << "\n";
        good = true;
      } else
        us[a[i]] = i;
    }
  }
  if (not good) cout << "IMPOSSIBLE\n";

  return 0;
}

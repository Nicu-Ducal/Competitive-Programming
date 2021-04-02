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
    string s; cin >> s;
    int n = s.size();
    if (s[0] == s[n - 1]) {
      cout << "NO\n";
      continue;
    }
    char f = s[0], l = s[n - 1];
    vector<int> b1, b2;
    for (int i = 0; i < n; i++) {
      if (s[i] == f) b1.push_back(1), b2.push_back(1);
      else if (s[i] == l) b1.push_back(-1), b2.push_back(-1);
      else b1.push_back(1), b2.push_back(-1);
    }
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; i++) {
      ans1 += b1[i];
      if (ans1 < 0) break;
    }
    for (int i = 0; i < n; i++) {
      ans2 += b2[i];
      if (ans2 < 0) break;
    }
    //cout << ans1 << ' ' << ans2 << "\n";
    if (ans1 == 0 or ans2 == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}

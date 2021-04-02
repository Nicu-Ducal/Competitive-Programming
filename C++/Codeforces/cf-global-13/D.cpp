#include <bits/stdc++.h>
using namespace std;

template <typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
using i64 = long long int;

const int INF = INT_MAX, MOD = 1e9 + 7;
const double EPS = 1e-9, PI = acos(-1);
const int dx[] = {0, 0, 0, -1, 1, -1, 1, 1, -1};
const int dy[] = {0, -1, 1, 0, 0, -1, 1, -1, 1};

int count_bits(int num) {
  int count = 0;
  while (num) {
    count += num & 1;
    num >>= 1;
  }
  return count;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  int tests; cin >> tests;
  while (tests--) {
    int u, v;
    cin >> u >> v;
    if (u == v) {
      cout << "YES\n";
    } else if (u > v) {
      cout << "NO\n";
    } else {
      bool good = true;
      int bits_u = 0, bits_v = 0;
      while (u > 0 or v > 0) {
        if (u & 1) bits_u++;
        if (v & 1) bits_v++;
        if (bits_v > bits_u) {
          good = false;
          break;
        }
        u = u >> 1, v = v >> 1;
      }
      if (good)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }


  return 0;
}

#include <bits/stdc++.h>
using namespace std;

template <typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
using i64 = long long int;

const int INF = INT_MAX, MOD = 1e9 + 7;
const double EPS = 1e-9, PI = acos(-1);
const int dx[] = {0, 0, 0, -1, 1, -1, 1, 1, -1};
const int dy[] = {0, -1, 1, 0, 0, -1, 1, -1, 1};

bool check(int64_t n) {
  string num = to_string(n);
  set<int> digits(num.begin(), num.end());
  if (num.size() == digits.size()) return true;
  return false;
}

int64_t sum(int64_t num) {
  int64_t ans = 0;
  while (num > 0) {
    ans += num % 10;
    num /= 10;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  int tests; cin >> tests;
  while (tests--) {
    int n = 0;
    int x; cin >> x;
    if (x > 45) {
      cout << "-1\n";
      continue;
    }
    while(++n) {
      //printf("%d\n", n);
      if (sum(n) == x and check(n)) {
        cout << n << "\n";
        break;
      }
    }
  }

  return 0;
}

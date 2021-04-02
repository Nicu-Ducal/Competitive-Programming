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
    int N; cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
      cin >> a[i];
    int ans = 0;
    for (int i = 1; i < N; i++) {
      if (max(a[i], a[i - 1]) > 2 * min(a[i], a[i - 1])) {
        bool ok = false;
        int cur = a[i - 1];
        int next;
        while (not ok) {
          if (cur < a[i])
            next = 2 * cur;
          else
            next = (cur & 1 ? cur / 2 : cur / 2 + 1);
          cur = next;
          ans++;
          if (max(cur, a[i]) > 2 * min(cur, a[i]))
            ok = true;
          printf("%d\n", cur);
        }
      }
    }
    cout << ans << "\n";
  }

  return 0;
}


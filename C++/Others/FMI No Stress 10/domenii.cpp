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
  
  ifstream cin("domenii.in");
  ofstream cout("domenii.out");

  int N;
  string S;
  cin >> N >> S;
  vector<int> cnt(30, 0);
  vector<int> prefix_sums(N + 1, 0), last_point(N + 1, -1);
  prefix_sums[0] = (S[0] == '.' ? 1 : 0);
  last_point[0] = (S[0] == '.' ? 0 : -1);
  for (int i = 1; i < N; i++) {
    last_point[i] = (S[i] == '.' ? i : last_point[i - 1]);
    prefix_sums[i] = prefix_sums[i - 1] + (last_point[i] == i);
  }

  int total = 0;
  int64_t ans = 0;
  if (N <= 2) {
    cout << ans << '\n';
    return 0;
  }

  // cout << prefix_sums << " " << last_point << "\n";

  if (S[N - 1] != '.') {
    ++cnt[S[N - 1] - 'a'];
    ++total;
  }
  for (int i = N - 2; i >= 0; i--) {
    if (last_point[i] == -1) break;
    if (S[i] == '.') continue;
    int cur = total - cnt[S[i] - 'a'];
    ans = ans + (int64_t) prefix_sums[i] * (int64_t) cur;
    ++total;
    ++cnt[S[i] - 'a'];
  }
  cout << ans << "\n";

  return 0;
}

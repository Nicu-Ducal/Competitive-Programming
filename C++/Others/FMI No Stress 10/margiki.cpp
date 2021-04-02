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

//  ifstream cin("margiki.in");
//  ofstream cout("margiki.out");
  
  int N; cin >> N;
  vector<int> dp(4, 0);
  dp[2] = 1;
  for (int i = 1; i <= N; i++) {
    dp[3] = 0;
    if (i >= 1) dp[3] = (dp[3] + dp[2]) % MOD;
    if (i >= 2) dp[3] = (dp[3] + dp[1]) % MOD;
    if (i >= 3) dp[3] = (dp[3] + dp[0]) % MOD;
    for (int i = 0; i < 3; i++) dp[i] = dp[i + 1];
  }
  cout << dp[3] << "\n";

  return 0;
}

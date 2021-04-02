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

  ifstream cin("stv.in");
  ofstream cout("stv.out");

  int N, M;
  cin >> N >> M;
  vector<set<pair<int, int>>> ballots(N);
  vector<vector<int>> index(M + 1, vector<int>(N, -1));
  for (int i = 0; i < N; i++) {
    int num; cin >> num;
    for (int j = 1; j <= num; j++) {
      int cand; cin >> cand;
      index[cand][i] = j;
      ballots[i].insert({j, cand});
    }
  }
  vector<int> ans;
  vector<bool> out(M + 1, false);
  for (int i = 1; i < M; i++) {
    // Count the loser
    vector<int> cnt(M + 1, 0);
    for (int j = 0; j < N; j++) {
      int best = ballots[j].begin()->second;
      cnt[best]++;
    }
    int worst = -1;
    for (int i = 1; i <= M; i++) {
      if (worst == -1 and not out[i]) worst = i;
      if (not out[i] and cnt[i] <= cnt[worst]) worst = i;
    }
    // Delete the worst;
    for (int i = 0; i < N; i++) {
      if (index[worst][i] != -1) {
        ballots[i].erase({index[worst][i], worst});
      }
    }
    // Append to ans
    ans.push_back(worst);
    out[worst] = true;
  }

  for (int i = 1; i <= M; i++)
    if (not out[i])
      cout << i << " ";
  for (int i = M - 2; i >= 0; i--)
    cout << ans[i] << " ";

  return 0;
}

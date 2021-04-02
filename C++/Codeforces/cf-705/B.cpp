#include <bits/stdc++.h>
using namespace std;

template <typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
using i64 = long long int;

const int INF = INT_MAX, MOD = 1e9 + 7;
const double EPS = 1e-9, PI = acos(-1);
const int dx[] = {0, 0, 0, -1, 1, -1, 1, 1, -1};
const int dy[] = {0, -1, 1, 0, 0, -1, 1, -1, 1};

unordered_map<int, int> mirror;
void init_mirror() {
  mirror[0] = 0;
  mirror[1] = 1;
  mirror[2] = 5;
  mirror[3] = -2;
  mirror[4] = -2;
  mirror[5] = 2;
  mirror[6] = -2;
  mirror[7] = -2;
  mirror[8] = 8;
  mirror[9] = -2;
}

vector<int> reflection(string time) {
  vector<int> ans;
  for (char x: time)
    ans.push_back(mirror[x - '0']);
  reverse(ans.begin(), ans.end());
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  init_mirror();
  int tests; cin >> tests;
  while (tests--) {
    int h, m;
    cin >> h >> m;
    string time; cin >> time;
    vector<int> refl = reflection(time);
    for
  }

  return 0;
}

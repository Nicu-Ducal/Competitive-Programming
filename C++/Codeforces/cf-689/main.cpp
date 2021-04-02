#include <bits/stdc++.h>
using namespace std;

template <typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
using i64 = long long int;

const int INF = INT_MAX, MOD = 1e9 + 7;
const double EPS = 1e-6, PI = acos(-1);
const int dx[] = {0, 0, 0, -1, 1, -1, 1, 1, -1};
const int dy[] = {0, -1, 1, 0, 0, -1, 1, -1, 1};

struct Divide {
  unordered_map<int64_t, bool> mp;
  set<pair<int, int>> marked;
  vector<int64_t> prefix_sum;

 // Divide() {}

  void prefix(vector<int64_t>& a) {
    prefix_sum.resize((int) a.size() + 1, 0);
    prefix_sum[0] = 0;
    for (int i = 1; i <= (int) a.size(); i++)
      prefix_sum[i] = prefix_sum[i - 1] + a[i - 1];
  }

  void solve(vector<int64_t>& a) {
    prefix(a);
    find_sums(a, 0, (int) a.size() - 1);
  }

  void find_sums(vector<int64_t>& a, int l, int r) {
    if (l > r or marked.find({l, r}) != marked.end()) return;
    if (l == r) {
      //printf("%d here\n", l);
      marked.insert({l, r});
      mp[a[l]] = true;
    } else {
      marked.insert({l, r});
      mp[prefix_sum[r + 1] - prefix_sum[l]] = true;
      int64_t num = (a[l] + a[r]) / 2;
      //printf("%d %d\n", l, r);
      int mid = int(upper_bound(a.begin(), a.end(), num) - a.begin()) - 1;
      find_sums(a, l, mid);
      find_sums(a, mid + 1, r);
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  int tests; cin >> tests;
  while (tests--) {
    int n, q; cin >> n >> q;
    vector<int64_t> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    Divide divide;
    divide.solve(a);

    //cout << upper_bound(a.begin(), a.begin() + 2, 5) - a.begin() << "\n";
    while (q--) {
      int s;
      cin >> s;
      cout << (divide.mp[s] ? "Yes\n" : "No\n");
    }
  }

  return 0;
}

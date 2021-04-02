#include <bits/stdc++.h>
using namespace std;

template <typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
using i64 = long long int;

const int INF = INT_MAX, MOD = 1e9 + 7;
const double EPS = 1e-9, PI = acos(-1);
const int dx[] = {0, 0, 0, -1, 1, -1, 1, 1, -1};
const int dy[] = {0, -1, 1, 0, 0, -1, 1, -1, 1};

const int MAX_NUM = 2e5 + 5;
int prime_factor[MAX_NUM];

void compute_sieve() {
  prime_factor[1] = 1;
  for (int i = 2; i < MAX_NUM; i++)
    if (i & 1)
      prime_factor[i] = i;
    else
      prime_factor[i] = 2;

  for (int p = 3; p < MAX_NUM; p++) {
    if (prime_factor[p] == p) {
      for (int mult = p * p; mult < MAX_NUM; mult += p) {
        //if (mult > 2e5) printf("%d\n", mult);
        if (prime_factor[mult] == mult)
          prime_factor[mult] = p;
      }
    }
  }
}

void factorize(int num, vector<int>& ans) {
  ans.push_back(1);
  while (num != 1) {
    int cur = prime_factor[num];
    if (ans.back() != cur)
      ans.push_back(cur);
    num /= cur;
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  compute_sieve();
//  int n, q;
//  cin >> n >> q;
//  vector<int> a(n), fact(MAX_NUM, 0);
//  vector<int> factors;
//  int _gcd;
//  for (int i = 0; i < n; i++) {
//    cin >> a[i];
//    if (i == 0) _gcd = a[i];
//    else _gcd = gcd(a[i], _gcd);
//    factorize(a[i], factors);
//    for (int i = 1; i < (int) factors.size(); i++)
//      fact[factors[i]]++;
//    factors.clear();
//  }

//  while (q--) {
//    int idx, x; cin >> idx >> x;
//    factorize(x, factors);
//    for (int i = 1; i < n; i++) {
//      if (a[idx] % factors[i] != 0) {
//        fact[factors[i]]++;
//        if (fact[factors[i]] == n)
//          _gcd *= factors[i];
//      }
//    }
//    a[idx] *= x;
//    factors.clear();
//  }

  return 0;
}


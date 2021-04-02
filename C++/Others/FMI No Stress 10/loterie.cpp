#include <bits/stdc++.h>
using namespace std;

template <typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
using i64 = long long int;

const int INF = INT_MAX, MOD = 1e9 + 7;
const double EPS = 1e-9, PI = acos(-1);
const int dx[] = {0, 0, 0, -1, 1, -1, 1, 1, -1};
const int dy[] = {0, -1, 1, 0, 0, -1, 1, -1, 1};

/**
 * Author: Neeecu
 * Algorithm: Sieve of Eratosthenes and Totient Function
 * Complexity: O(N * log(log(N)))
 */
namespace Numeric {
  const int MAX_N = 50005;
  vector<bool> sieve(MAX_N, true);
  vector<int64_t> prefix_sums(MAX_N, 0);
  vector<int64_t> phi(MAX_N, 0);

  vector<int64_t> remove(MAX_N, 1);

  void compute_sieve() {
    sieve[0] = sieve[1] = false;
    for (int prim = 2; prim < MAX_N; prim++) {
      if (sieve[prim])
        for (int mult = 2 * prim; mult < MAX_N; mult += prim)
          sieve[mult] = false;
    }
  }

  void compute_phi() {
    phi[0] = 0; phi[1] = 0;
    for (int i = 2; i < MAX_N; i++)
      phi[i] = i;

    for (int i = 2; i < MAX_N; i++) {
      if (phi[i] == i) {
        for (int j = i; j < MAX_N; j += i)
          phi[j] -= phi[j] / i;
      }
    }
  }

  void compute_sums() {
    prefix_sums[0] = 0;
    for (int i = 1; i < MAX_N; i++)
      /// For primes, change for sieve
      /// For coprimes, change for totient
      prefix_sums[i] = prefix_sums[i - 1] + phi[i];
  }



  int64_t query(int a, int b) {
    if (a > b) swap(a, b);
    // Are a and b greater than 0? a = max(0, a); b = max(0, b);
    int64_t ans = prefix_sums[b] - prefix_sums[a - 1];
    for (int i = 1; i <= a - 1; i++) {
      for (int j = a; j <= b; j++) {
        if (__gcd(i,j) == 1) ans--;
      }
    }
    return ans;
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  ifstream cin("loterie.in");
  ofstream cout("loterie.out");
  
  Numeric::compute_phi();
  Numeric::compute_sums();
  int Q; cin >> Q;
  //for (int i = 0; i <= 5; i++) cout << Numeric::phi[i] << ' ';
  cout << "\n";
  while (Q--) {
    int A, B;
    cin >> A >> B;
    cout << Numeric::query(A, B) << "\n";
  }

  return 0;
}

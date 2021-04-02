#include <bits/stdc++.h>
using namespace std;

template <typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
using i64 = long long int;

const int INF = 1e9, MOD = 1e9 + 7;
const double EPS = 1e-9, PI = acos(-1);
const int dx[] = {0, 0, 0, -1, 1, -1, 1, 1, -1};
const int dy[] = {0, -1, 1, 0, 0, -1, 1, -1, 1};
const int M = 40;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    int t; cin >> t;
    while (t--) {
        int n, ans = 0;
        cin >> n;
        vector<int64_t> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        vector<vector<int64_t>> dp(n + 1, vector<int64_t>(M, 1e10));

        // dp[i][j] - minimal difference when we take i numbers at j minute
        sort(a.begin(), a.end());
        for (int i = 0; i < M; i++) dp[0][i] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < M; j++) {
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1] + abs(j - a[i]));
            }
        }
        cout << dp[n][M - 1] << "\n";
    }

    return 0;
}
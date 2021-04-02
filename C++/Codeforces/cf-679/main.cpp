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

    int n;
    vector<int> a(7), notes;
    for (int i = 1; i <= 6; i++) cin >> a[i];
    cin >> n;
    notes.resize(n);
    for (int i = 0; i < n; i++) cin >> notes[i];
    sort(a.begin(), a.end());
    sort(notes.begin(), notes.end());
    multiset<pair<int, int>> ms;
    for (int i = 0; i < n; i++) ms.insert({notes[i] - a[1], 1});
    int ans = INF;
    while (true) {
        ans = min(ans, ms.rbegin()->first - ms.begin()->first);
        auto cur = *ms.rbegin();
        ms.erase(*ms.rbegin());
        if (cur.second == 6) break;
        ms.insert({cur.first + a[cur.second] - a[cur.second + 1], cur.second + 1});
    }
    cout << ans << "\n";

    return 0;
}
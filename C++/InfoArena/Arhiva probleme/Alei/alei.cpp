#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " = " << x << "\n"
#define all(x) (x).begin(),(x).end()
#define len(x) (x).length()
#define sqr(x) (x) * (x)
#define x first
#define y second

using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B>
ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

const int INF = INT_MAX;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1);
const int dx[] = {0, 0, 0, -1, 1, -1, 1, 1, -1};  /// 0, U, D, L, R
const int dy[] = {0, -1, 1, 0, 0, -1, 1, -1, 1};  /// LU, RD, RU, LD

ll t, n;

struct Lee {
    vector<vector<int>> dist;
    pii p1, p2;
    int n;

    Lee(int _n = 0) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        vector<int> tmp;
        for (int i = 1; i <= n; i++) tmp.push_back(-1);
        dist.resize(n, tmp);
    }

    int LeeBFS() {
        queue<pii> q;
        q.push(p1);
        while (not q.empty()) {
            pii cur = q.front(); q.pop();
            for (int i = 1; i <= 4; i++) {
                pii next = {cur.x + dx[i], cur.y + dy[i]};
                if (next.x < 0 or next.x >= n or next.y < 0 or next.y >= n) continue;
                else if (dist[next.x][next.y] == -2) continue;
                else if (dist[next.x][next.y] == -1) {
                    dist[next.x][next.y] = 1 + dist[cur.x][cur.y];
                    if (next == p2) return dist[next.x][next.y];
                    q.push({next.x, next.y});
                }
            }
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ifstream cin("alee.in");
    ofstream cout("alee.out");

    int m, x, y;
    cin >> n >> m;
    Lee lee(n);
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        lee.dist[--x][--y] = -2;
    }
    cin >> x >> y;
    lee.p1 = {--x, --y}, lee.dist[x][y] = 1;
    cin >> x >> y;
    lee.p2 = {--x, --y};

    cout << lee.LeeBFS();

    return 0;
}

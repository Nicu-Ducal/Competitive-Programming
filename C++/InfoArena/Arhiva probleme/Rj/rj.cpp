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
const int dx[] = {0, 0, 0, -1, 1, -1, 1, 1, -1};
const int dy[] = {0, -1, 1, 0, 0, -1, 1, -1, 1};

ll t, n, m;

struct Lee {
    /// vector<string> adj;
    vector<vector<pii>> dist;
    pii Ro, Ju, ans;
    int n, m, time = INF;

    Lee(int _n = 0, int _m = 0) {
        init(_n, _m);
    }

    void init(int _n, int _m) {
        n = _n, m = _m;
        /// adj.resize(n);
        vector<pii> tmp;
        for (int i = 0; i < m; i++) tmp.push_back({-1, -1});
        dist.resize(n, tmp);
    }

    void BFS(pii s, pii t, int turn) {
        queue<pii> q;
        q.push(s);
        while (not q.empty()) {
            pii cur = q.front(); q.pop();
            for (int i = 1; i <= 8; i++) {
                pii next = {cur.x + dx[i], cur.y + dy[i]};
                if (next.x < 0 or next.x >= n or next.y < 0 or next.y >= m) continue;
                else if (dist[next.x][next.y] == make_pair(-1, -1)) continue;
                else {
                    if (next != s and ((turn == 1 and dist[next.x][next.y].first == 0) or (turn == 2 and dist[next.x][next.y].second == 0))) {
                        if (turn == 1) dist[next.x][next.y].first = 1 + dist[cur.x][cur.y].first;
                        else dist[next.x][next.y].second = 1 + dist[cur.x][cur.y].second;
                        if (t == make_pair(next.x, next.y)) return;
                        q.push({next.x, next.y});
                    }
                }
            }
        }
    }

    void LeeBFS() {
        BFS(Ro, Ju, 1);
        BFS(Ju, Ro, 2);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dist[i][j].first == dist[i][j].second and (dist[i][j].first > 0)) {
                    if (time > dist[i][j].first) {
                        time = dist[i][j].first;
                        ans = {i, j};
                    }
                }
            }
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ifstream cin("rj.in");
    ofstream cout("rj.out");

    cin >> n >> m;
    Lee lee(n, m);
    char c;
    cin.get();

    /// Fucking input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin.get(c);
            /// if (c == ' ') c = '_';
            if (c == '\n') break;
            if (c == 'R') lee.Ro.x = i, lee.Ro.y = j;
            if (c == 'J') lee.Ju.x = i, lee.Ju.y = j;
            if (c != 'X') lee.dist[i][j] = {0, 0};
            /// lee.adj[i].push_back(c);
            if (j == m - 1) cin.get();
        }
    }

    lee.LeeBFS();
    cout << lee.time + 1 << " " << lee.ans.x + 1 << " " << lee.ans.y + 1 << "\n";

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

template <typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
using i64 = long long int;

const int INF = INT_MAX, MOD = 1e9 + 7;
const double EPS = 1e-9, PI = acos(-1);
const int dx[] = {0, 0, 0, -1, 1, -1, 1, 1, -1};
const int dy[] = {0, -1, 1, 0, 0, -1, 1, -1, 1};

struct Lee {
    vector<vector<int>> adj, dist;
    vector<vector<bool>> marked;
    int n, m;

    Lee(int _n = 0, int _m = 0) {
        init(_n, _m);
    }

    void init(int _n, int _m) {
        n = _n;
        m = _m;
        adj.resize(n, vector<int>(m, -1));
        dist.resize(n, vector<int>(m, INF));
        marked.resize(n, vector<bool>(m, false));
    }

    void LeeBFS(pair<int, int> prince, pair<int, int> castle) {
        deque<pair<int, int>> deq;
        deq.push_back({prince.x, prince.y});
        dist[prince.x][prince.y] = 0;
        while (not deq.empty()) {
            pair<int, int> cur = deq.front();
            deq.pop_front();
            if (cur == castle) return;
            if (marked[cur.x][cur.y]) continue;
            marked[cur.x][cur.y] = true;
            for (int i = 1; i <= 4; i++) {
                pair<int, int> next = {cur.x + dx[i], cur.y + dy[i]};
                if (next.x < 0 or next.x >= n or next.y < 0 or next.y >= m) continue;
                else if (not marked[next.x][next.y]) {
                    if (adj[next.x][next.y] == adj[cur.x][cur.y] and dist[next.x][next.y] > dist[cur.x][cur.y]) {
                        dist[next.x][next.y] = dist[cur.x][cur.y];
                        deq.push_front({next.x, next.y});
                    }
                    else if (adj[next.x][next.y] != adj[cur.x][cur.y] and dist[next.x][next.y] > dist[cur.x][cur.y] + 1) {
                        dist[next.x][next.y] = dist[cur.x][cur.y] + 1;
                        deq.push_back({next.x, next.y});
                    }
                }
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    ifstream cin("padure.in");
    ofstream cout("padure.out");

    int n, m, px, py, cx, cy;
    cin >> n >> m;
    Lee lee(n, m);
    cin >> px >> py >> cx >> cy;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> lee.adj[i][j];

    lee.LeeBFS({px - 1, py - 1}, {cx - 1, cy - 1});
    // cout << lee.dist << "\n";
    cout << lee.dist[cx - 1][cy - 1];

    return 0;
}
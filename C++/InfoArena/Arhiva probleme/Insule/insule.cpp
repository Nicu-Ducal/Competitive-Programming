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

ll t, n, m;

struct Lee {
    vector<string> adj;
    vector<vector<bool>> marked;
    vector<int> isl;
    int n, m, ans = INF;

    Lee(int _n = 0, int _m = 0) {
        init(_n, _m);
    }

    void init(int _n, int _m) {
        n = _n; m = _m;
        marked.resize(n);
        for (int i = 0; i < n; i++) marked[i].resize(m, false);
        isl.resize(4, 0);
    }

    bool hasWater(int x, int y) {
        for (int i = 1; i <= 4; i++) {
            pii nei = {x + dx[i], y + dy[i]};
            if (nei.x < 0 or nei.x >= n or nei.y < 0 or nei.y >= m) continue;
            else if (adj[nei.x][nei.y] == '0') return true;
        }
        return false;
    }

    void DFS(pii node, char type) {
        marked[node.x][node.y] = true;
        for (int i = 1; i <= 4; i++) {
            pii next = {node.x + dx[i], node.y + dy[i]};
            if (next.x < 0 or next.x >= n or next.y < 0 or next.y >= m) continue;
            else if (adj[next.x][next.y] == type and not marked[next.x][next.y]) DFS(next, type);
        }
    }

    void LeeBFS() {
        queue<pair<pii, int>> q;
        /// Marking all islands with a DFS
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (adj[i][j] == '1' and hasWater(i, j)) q.push({{i, j}, 0});
                if (adj[i][j] != '0' and not marked[i][j]) {
                    DFS({i, j}, adj[i][j]);
                    isl[adj[i][j] - '0']++;
                }
            }
        }
        for (int i = 0; i < n; i++) fill(all(marked[i]), false);
        /// Finding the bridge with the BFS
        while (not q.empty()) {
            pii cur = q.front().first;
            int dist = q.front().second;
            q.pop();
            for (int i = 1; i <= 4; i++) {
                pii next = {cur.x + dx[i], cur.y + dy[i]};
                if (next.x < 0 or next.x >= n or next.y < 0 or next.y >= m) continue;
                else if (adj[next.x][next.y] == '0' and not marked[next.x][next.y])
                    marked[next.x][next.y] = true, q.push({next, dist + 1});
                else if (adj[next.x][next.y] == '2' and dist != 0) {
                    ans = dist;
                    return;
                }
            }
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ifstream cin("insule.in");
    ofstream cout("insule.out");

    cin >> n >> m;
    Lee lee(n, m);
    string row;
    for (int i = 0; i < n; i++) {
        cin >> row;
        lee.adj.push_back(row);
    }

    lee.LeeBFS();
    cout << lee.isl[1] << " " << lee.isl[2] << " " << lee.isl[3] << " " << lee.ans;

    return 0;
}

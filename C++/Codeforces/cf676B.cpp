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
vector<string> grid;
vector<vector<bool>> marked;
vector<pii> ans;

char cmpl(char i) {
    return (i ? '1' : '0');
}

bool BFS(pii cell, char type, vector<vector<bool>> &marked) {
    marked[n - 1][n - 1] = false;
    queue<pii> q;
    q.push(cell);
    while (not q.empty()) {
        pii cur = q.front();
        marked[cur.x][cur.y] = true;
        q.pop();
        for (int i = 1; i <= 4; i++) {
            pii next = {cur.x + dx[i], cur.y + dy[i]};
            if (next.x < 0 or next.y < 0 or next.x >= n or next.y >= n) continue;
            else if (grid[next.x][next.y] == type and not marked[next.x][next.y]) {
                q.push(next);
            }
            else if (grid[next.x][next.y] == 'F') {
                marked[n - 1][n - 1] = true;
            }
        }
    }
    return marked[n - 1][n - 1];
}

bool change(pii p1, pii p2) {
    for (auto& row: marked) row.resize(n, false);
    grid[p1.x][p1.y] = cmpl(grid[p1.x][p1.y]);
    if (p2 != pii(-1, -1)) grid[p2.x][p2.y] = cmpl(grid[p2.x][p2.y]);
    if (BFS({0, 0}, '0', marked) or BFS({0, 0}, '1', marked)){
        grid[p1.x][p1.y] = cmpl(grid[p1.x][p1.y]);
        if (p2 != pii(-1, -1)) grid[p2.x][p2.y] = cmpl(grid[p2.x][p2.y]);
        return false;
    }
    ans.push_back(p1);
    if (p2 != pii(-1, -1)) ans.push_back(p2);
    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    cin >> t;
    while (t--) {
        cin >> n;
        marked.resize(n);
        ans.resize(0);
        for (auto& row: marked) row.resize(n, false);
        string s;
        for (int i = 0; i < n; i++) {
            cin >> s;
            grid.push_back(s);
        }
        bool zero = BFS({0, 0}, '0', marked), one = BFS({0, 0}, '1', marked);
        if (zero or one) {
            if (change({n - 2, n - 1}, {-1, -1})) {
                cout << ans.size() << "\n";
                for (auto el: ans) cout << el.x + 1 << " " << el.y + 1 << "\n";
                continue;
            }
            else if (change({n - 1, n - 2}, {-1, -1})) {
                cout << ans.size() << "\n";
                for (auto el: ans) cout << el.x + 1 << " " << el.y + 1 << "\n";
                continue;
            }
            else if (change({n - 2, n - 2}, {-1, -1})) {
                cout << ans.size() << "\n";
                for (auto el: ans) cout << el.x + 1 << " " << el.y + 1 << "\n";
                continue;
            }
            else if (change({n - 1, n - 2}, {n - 2, n - 1})) {
                cout << ans.size() << "\n";
                for (auto el: ans) cout << el.x + 1 << " " << el.y + 1 << "\n";
                continue;
            }
            else if (change({n - 2, n - 1}, {n - 2, n - 2})) {
                cout << ans.size() << "\n";
                for (auto el: ans) cout << el.x + 1 << " " << el.y + 1 << "\n";
                continue;
            }
            else if (change({n - 1, n - 2}, {n - 2, n - 2})) {
                cout << ans.size() << "\n";
                for (auto el: ans) cout << el.x + 1 << " " << el.y + 1 << "\n";
                continue;
            }
        } else {
            cout << "0\n";
        }
    }

    return 0;
}

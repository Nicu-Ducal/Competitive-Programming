#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " = " << x << "\n"
#define all(x) (x).begin(),(x).end()
#define len(x) (x).length()
#define sqr(x) (x) * (x)

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

int t, n;

struct Graph {
    vector<vector<pii>> adj;
    vector<bool> marked;
    vector<int> euler, lastChecked;

    Graph(int n = -1, int m = -1) {
        init(n, m);
    }

    void init(int n, int m) {
        adj.resize(n + 1);
        marked.resize(m + 1, false);
        lastChecked.resize(n + 1, 0);
    }

    void addEdge(int u, int v, int edge) {
        adj[u].push_back({v, edge});
        adj[v].push_back({u, edge});
    }

    bool checkDegree() {
        for (int i = 1; i <= n; i++) {
            int degree = 0;
            for (auto node: adj[i]) {
                if (i == node.first) degree += 2;
                else degree++;
            }
            if (degree & 1) return false;
        }
        return true;
    }

    void findEuler() {
        stack<int> stk;
        stk.push(1);
        while (not stk.empty()) {
            int node = stk.top();
            for (int i = lastChecked[node]; i < adj[node].size(); i++, lastChecked[node]++) {
                auto nxt = adj[node][i];
                if (not marked[nxt.second]) {
                    marked[nxt.second] = true;
                    stk.push(nxt.first);
                    break;
                }
            }
            if (lastChecked[node] == adj[node].size()) {
                euler.push_back(node);
                stk.pop();
            }
        }
        reverse(all(euler));
        euler.pop_back();
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ifstream cin("ciclueuler.in");
    ofstream cout("ciclueuler.out");

    int m, u, v;
    cin >> n >> m;
    Graph g(n, m);
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        g.addEdge(u, v, i);
    }

    if (g.checkDegree()) {
        g.findEuler();
        for (auto node: g.euler) cout << node << " ";
    } else cout << "-1\n";

    return 0;
}

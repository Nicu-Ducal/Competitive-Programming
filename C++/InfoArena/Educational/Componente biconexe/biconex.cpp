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

ll t, n;

struct Graph {
    vector<vector<int>> adj, biconnected;
    vector<int> up, in;
    vector<bool> marked;
    stack<int> stk;
    int time = 0;

    Graph(int n = -1) {
        init(n);
    }

    void init(int n) {
        adj.resize(n + 1);
        marked.resize(n + 1, false);
        up.resize(n + 1, 0);
        in.resize(n + 1, 0);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int node, int par = -1) {
        stk.push(node);
        marked[node] = true;
        in[node] = up[node] = time++;
        for (auto nxt: adj[node]) {
            if (nxt == par) continue;
            if (not marked[nxt]) {
                dfs(nxt, node);
                up[node] = min(up[node], up[nxt]);
                if (up[nxt] >= in[node]) {
                    vector<int> bicon;
                    while (stk.top() != nxt) {
                        bicon.push_back(stk.top());
                        stk.pop();
                    }
                    bicon.push_back(nxt);
                    bicon.push_back(node);
                    stk.pop();
                    biconnected.push_back(bicon);
                }
            } else
                up[node] = min(up[node], in[nxt]);
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ifstream cin("biconex.in");
    ofstream cout("biconex.out");

    ll m, u, v;
    cin >> n >> m;
    Graph g(n);
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.dfs(1);

    cout << g.biconnected.size() << "\n";
    for (auto component: g.biconnected) {
        for (auto node: component) cout << node << " ";
        cout << "\n";
    }

    return 0;
}

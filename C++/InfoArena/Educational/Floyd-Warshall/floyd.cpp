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

const int INF = 1e9;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1);

ll t, n;

struct graph {
    vector<vector<pii>> adj;
    vector<vector<int>> dist;
    int vert;

    graph(int n = 0) : vert(n) {
        init(n);
    }

    void init(int n) {
        adj.resize(n + 1);
        dist.resize(n + 1);
        for (int i = 0; i <= n; i++)
            dist[i].resize(n + 1, 0);
    }

    void add(int from, int to, int distance) {
        adj[from].emplace_back(to, distance);
        dist[from][to] = distance;
    }

    void allPairShortest() {
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++) {
                    if ((dist[i][j] > dist[i][k] + dist[k][j] or dist[i][j] == 0) and i != j and dist[i][k] and dist[k][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ifstream cin("royfloyd.in");
    ofstream cout("royfloyd.out");

    cin >> n;

    graph g(n);
    int dist;
    for (int from = 1; from <= n; from++) {
        for (int to = 1; to <= n; to++) {
            cin >> dist;
            g.add(from, to, dist);
        }
    }

    g.allPairShortest();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << g.dist[i][j] << " ";
        cout << "\n";
    }

    return 0;
}

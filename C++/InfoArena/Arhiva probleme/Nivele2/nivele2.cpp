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

struct graph {
    vector<vector<int>> adj;
    vector<bool> viz;
    vector<pii> q;

    graph(int n = 0) {
        adj.resize(n + 1);
        viz.resize(n + 1, false);
    }

    void add(int from, int to) {
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    void bfs() {
        q.push_back({1, 1});

        for (int i = 0; i < (int) q.size(); i++) {
            int cur = q[i].first;
            int lvl = q[i].second;
            viz[cur] = true;

            for (auto next: adj[cur])
                if (not viz[next])
                    q.push_back({next, lvl + 1});
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ifstream cin("nivele2.in");
    ofstream cout("nivele2.out");

    int from, to;
    cin >> n;

    graph g(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> from >> to;
        g.add(from, to);
    }

    g.bfs();
    int curlvl = 0;
    for (int i = 0; i < g.q.size(); i++) {
        if (curlvl != g.q[i].second) {
            curlvl++;
            if (curlvl > 1) cout << "\n";
            cout << "nivelul " << curlvl << ": ";
        }
        cout << g.q[i].first << " ";
    }


    return 0;
}

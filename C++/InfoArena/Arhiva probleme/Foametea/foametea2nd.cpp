#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << "\n"
#define all(x) (x).begin(),(x).end()
#define len length()
#define sz size()
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sqr(x) (x) * (x)

using ull = unsigned long long;
using ll = long long;
using namespace std;

template <typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B>
ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

struct node {
    int num, L, C;
};

struct query {
    int node, time, kLeft;

    bool operator<(const query& rhs) const {
        return (this->time > rhs.time);
    }
};

const int INF = INT_MAX, maxN = 5005;
int t, n, k, m, a, ans = INF;
vector<int> s;
vector<vector<int>> dp;
vector<node> graph[maxN];
priority_queue<query> heap;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ifstream cin("foametea.in");
    ofstream cout("foametea.out");

    cin >> n >> m >> k;
    s.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 1; i <= m; i++) {
        node temp;
        cin >> a >> temp.num >> temp.L >> temp.C;
        graph[a].pb(temp);
    }

    dp.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        dp[i].resize(k + 1, INF);
    }

    dp[1][0] = 0;
    heap.push({1, 0, 0});
    while (not heap.empty()) {
        query curr = heap.top();
        heap.pop();

        for (auto next : graph[curr.node]){
            for (int sarm = 0; sarm <= s[curr.node]; sarm++) {
                if (curr.kLeft + sarm < next.C) continue;
                if (curr.kLeft + sarm > k) break;
                if (dp[next.num][curr.kLeft + sarm] > curr.time + next.L * (sqr(curr.kLeft + sarm - next.C) + 1)) {
                    dp[next.num][curr.kLeft + sarm] = curr.time + next.L * (sqr(curr.kLeft + sarm - next.C) + 1);
                    heap.push({next.num, dp[next.num][curr.kLeft + sarm], curr.kLeft + sarm - next.C});
                }
            }
        }
    }

    for (int i = 0; i <= k; i++)
        ans = min(ans, dp[n][i]);

    if (ans != INF) cout << ans;
    else cout << "Fomistul moare de foame";

    return 0;
}

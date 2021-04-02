/******** Ordered Set ********
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; */

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

using ull = unsigned long long;
using ll = long long;
using namespace std;

template<typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B>
ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

const int INF = INT_MAX, maxN = 1e5 + 10;
ll t, n, m, aux, x, y, ans, idx;
vector<int> graf[maxN], euler, height, Log2, first(maxN, -1);
vector< vector<int> > sparce;


void dfs(int nod, int hg){
    if (first[nod] == -1)
        first[nod] = idx;
    euler.pb(nod);
    height.pb(hg);
    ++idx;
    for (auto node : graf[nod]){
        dfs(node, hg + 1);
        euler.pb(nod);
        height.pb(hg);
        ++idx;
    }
}

void createLog(){
    aux = euler.size();
    Log2.resize(aux + 1, 0);
    for (int i = 2; i <= aux; i++)
        Log2[i] = 1 + Log2[i >> 1];
}

void buildSparce(){
    aux = euler.size();
    int aux_log = Log2[aux] + 2;
    sparce.resize(aux);
    for (auto &vec : sparce)
        vec.resize(aux_log, 0);

    for (int i = 0; i < aux; i++){
        sparce[i][0] = i;
    }
    for (int j = 1; (1 << j) <= aux; j++){
        for (int i = 0; i + (1 << j) - 1 < aux; i++){
            if (height[sparce[i][j - 1]] < height[sparce[i + (1 << (j - 1))][j - 1]])
                sparce[i][j] = sparce[i][j - 1];
            else
                sparce[i][j] = sparce[i + (1 << (j - 1))][j - 1];
        }
    }
}

int lca(int x, int y){
    if (first[x] <= first[y]){
        int diff = first[y] - first[x] + 1;
        int lg = Log2[diff];
        //cout << sparce[first[x]][lg] << "\n";
        //cout << sparce[first[x] + diff - (1 << lg)][lg] << "\n";
        return euler[(height[sparce[first[x]][lg]] < height[sparce[first[x] + diff - (1 << lg)][lg]]) ? sparce[first[x]][lg] : sparce[first[x] + diff - (1 << lg)][lg]];
    } else
        return lca(y, x);
}

int main(){
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ifstream cin("lca.in");
    ofstream cout("lca.out");

    cin >> n >> m;
    for (int i = 1; i <= n - 1; i++){
        cin >> aux;
        graf[aux].pb(i + 1);
    }

    dfs(1, 0);
    createLog();
    buildSparce();
    //cout << height << "\n";
    //cout << euler << Log2;
    /*for (int i = 0; i < sparce.size(); i++)
        cout << sparce[i] << "\n";*/

    while (m--){
        cin >> x >> y;
        cout << lca(x, y) << "\n";
    }


    return 0;
}

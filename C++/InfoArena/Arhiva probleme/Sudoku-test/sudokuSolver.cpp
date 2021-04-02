#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define debug(x) cerr << #x << " = " << x << "\n"
#define all(x) (x).begin(),(x).end()
#define len(x) (x).length()
#define size(x) (x).size()
#define sqr(x) (x) * (x)
#define pb push_back
#define fi first
#define se second

using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; /// Ordered Set : find_by_order, order_of_key
template <typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B>
ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

const int INF = INT_MAX;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1);
ll t, n, ans;
int sud[5][5];
bool row[5][5], col[5][5], grid[5][5], init[5][5];


int echivClass(int i, int j) {
    if (1 <= i and i <= 2) {
        if (1 <= j and j <= 2) return 1;
        else return 2;
    } else {
        if (1 <= j and j <= 2) return 3;
        else return 4;
    }
}

void afisare() {
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            cout << sud[i][j] << " ";
        }
        cout << "\n";
    }
}


void solve(int i, int j) {
    if (init[i][j]) {
        if (j < 4) solve(i, j + 1);
        else if (i < 4) solve(i + 1, 1);
        else if (i == 4 and j == 4) {
            ans++;
            afisare();
        }
    }
    else {
        for (int k = 1; k <= 4; k++) {
            if (not row[i][k] and not col[j][k] and not grid[echivClass(i, j)][k]) {
                sud[i][j] = k;
                row[i][k] = true;
                col[j][k] = true;
                grid[echivClass(i, j)][k] = true;

                if (j < 4) solve(i, j + 1);
                else if (i < 4) solve(i + 1, 1);
                else if (i == 4 and j == 4){
                    ans++;
                    afisare();
                }

                sud[i][j] = 0;
                row[i][k] = false;
                col[j][k] = false;
                grid[echivClass(i, j)][k] = false;
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ifstream cin("sudokuSolver.in");

    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++) {
            cin >> sud[i][j];
            if (sud[i][j]) init[i][j] = true;
            row[i][sud[i][j]] = true;
            col[j][sud[i][j]] = true;
            grid[echivClass(i, j)][sud[i][j]] = true;
        }

    solve(1, 1);
    cout << ans;

    return 0;
}

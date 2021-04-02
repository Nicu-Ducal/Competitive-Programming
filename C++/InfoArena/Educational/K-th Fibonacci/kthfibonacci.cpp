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
const ll MOD = 666013;
const double EPS = 1e-9;
const double PI = acos(-1);

ll t, n;

struct matrix {
    vector<vector<ll>> m;

    matrix() {
        m.resize(2);
        for (int i = 0; i < 2; i++) m[i].resize(2, 1);
        m[0][0] = 0;
    }

    matrix operator*(const matrix& rhs) {
        matrix ans;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                ll num = 0;
                for (int k = 0; k < 2; k++)
                    num = (num + (this->m[i][k] % MOD) * (rhs.m[k][j] % MOD)) % MOD;
                ans.m[i][j] = num % MOD;
            }
        }
        return ans;
    }
};

matrix binexp(matrix P, int pw) {
    // But 0?
    if (pw == 1) return P;
    else if (pw & 1) return P * binexp(P * P, (pw - 1) / 2);
    return binexp(P * P, pw / 2);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ifstream cin("kfib.in");
    ofstream cout("kfib.out");

    cin >> n;

    matrix F;
    F = binexp(F, n - 1);
    cout << F.m[1][1];

    return 0;
}

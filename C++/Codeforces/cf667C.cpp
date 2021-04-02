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

ll t, n;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    cin >> t;
    while (t--) {
        ll n, x, y;
        cin >> n >> x >> y;
        vector<ll> a;
        a.push_back(x);
        a.push_back(y);

        ll ans = y - x, ansi = 1;
        for (int i = 1; i <= n - 1; i++) {
            if ((y - x) % i == 0) {
                if ((y - x) / i < ans) {
                    ans = (y - x) / i;
                    ansi = i;
                }
            }
        }

        for (int i = 1; i < ansi; i++) {
            a.push_back(x + ans * i);
        }
        int ls = 1, gr = 1;
        for (int i = 1; i <= n - ansi - 1; i++) {
            if (x - ls * ans > 0) {
                a.push_back(x - ls * ans);
                ls++;
            } else {
                a.push_back(y + gr * ans);
                gr++;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}

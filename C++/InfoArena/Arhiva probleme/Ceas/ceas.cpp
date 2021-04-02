#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << "\n"
#define all(x) (x).begin(),(x).end()
#define len(x) (x).length()
#define size(x) (x).size()
#define sqr(x) (x) * (x)
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>

using ull = unsigned long long;
using ll = long long;
using namespace std;

template <typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B>
ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

const int INF = INT_MAX;
ll t, n, h1, m1, h2, m2, h3, m3;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ifstream cin("ceas.in");
    ofstream cout("ceas.out");

    cin >> h1 >> m1 >> h2 >> m2;
    h3 = h1, m3 = m1;
    m2 += h2 * 60;
    h3 %= 12;
    int pause = h3 * 5;
    if (m3 == pause)
        m2 -= 5;
    while (m2 > 0) {
        ++m3, --m2;
        if (m3 == 60) {
            m3 = 0;
            h3 = (h3 + 1) % 12;
            pause = h3 * 5;
        }
        if (m3 == pause)
            m2 -= 5;
    }

    if (h3 == 0) h3 = 12;
    cout << h3 << " " << m3;
    return 0;
}

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
ll t, n, k, sum, ans, fi, ls;
vector<int> v;
deque<int> deq;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ifstream cin("secv2.in");
    ofstream cout("secv2.out");

    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < k; i++) {
        deq.pb( i);
        sum += v[i];
    }

    ans = sum, fi = 0, ls = k - 1;
    int i = fi, j = ls;
    while (i <= j and j < n - 1) {
        if (sum > ans) {
            ls = j, fi = i, ans = sum;
        } else if (sum <= 0) {
            while (deq.back() - deq.front() + 1 >= k and sum <= 0) {
                ++i;
                sum -= v[deq.front()];
                deq.pop_front();
            }
        }
        ++j;
        deq.pb(j);
        sum += v[j];
    }
    if (sum > ans) {
        ls = j, fi = i, ans = sum;
    }

    cout << ++fi << " " << ++ls << " " << ans;

    return 0;
}

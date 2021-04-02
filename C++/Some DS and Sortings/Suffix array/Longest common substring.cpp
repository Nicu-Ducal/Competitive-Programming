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

const ll INF = INT_MAX, MOD = 1e9 + 7;
//ll t, n, m, k, ans;

void count_sort(vector<int> &p, vector<int> &c) {
    int n = size(p);
    vector<int> cnt(n), pos(n), aux(n);
    for (auto x : c)
        cnt[x]++;

    pos[0] = 0;
    for (int i = 1; i < n; i++)
        pos[i] = pos[i - 1] + cnt[i - 1];

    for (auto x : p) {
        int i = c[x];
        aux[pos[i]] = x;
        pos[i]++;
    }
    p = aux;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    string s1, s2, s;
    cin >> s1 >> s2;
    s = s1 + '$' + s2 + '#';
    int n = len(s), fs = len(s1);
    vector<int> p(n), c(n);

    // k = 0
    vector<pair<char, int>> a(n);
    for (int i = 0; i < n; i++) a[i] = {s[i], i};
    sort(all(a));
    for (int i = 0; i < n; i++) p[i] = a[i].se;
    c[p[0]] = 0;
    for (int i = 1; i < n; i++) {
        if (a[i].fi == a[i - 1].fi)
            c[p[i]] = c[p[i - 1]];
        else
            c[p[i]] = c[p[i - 1]] + 1;
    }

    // k -> k + 1;
    int k = 0;
    while ((1 << k) < n) {
        for (int i = 0; i < n; i++) p[i] = (p[i] - (1 << k) + n) % n;
        count_sort(p, c);

        vector<int> aux(n);
        aux[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            pair<int, int> now = {c[p[i]], c[(p[i] + (1 << k)) % n]};
            pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};
            if (now == prev)
                aux[p[i]] = aux[p[i - 1]];
            else
                aux[p[i]] = aux[p[i - 1]] + 1;
        }
        c = aux;
        k++;
    }

    // LCP
    k = 0;
    vector<int> lcp(n);
    for (int i = 0; i < n - 1; i++) {
        int pi = c[i];
        int j = p[pi - 1];
        while (s[i + k] == s[j + k]) k++;
        lcp[pi] = k;
        k = max(k - 1, 0);
    }

    ll ans = 0;
    string sans = "";
    // Longest common substring
    for (int i = 1; i < n; i++) {
        if ((p[i] < fs and p[i - 1] >= fs) or (p[i - 1] < fs and p[i] >= fs)) {
            if (ans < lcp[i]) {
                ans = lcp[i], sans = s.substr(p[i], ans);
            }
        }
    }
    cout << sans;

    return 0;
}

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

void radix_sort(vector<pair<pair<int, int>, int>> &b) {
    int n = size(b);
    vector<int> bucket(256, 0);
    for (int k = 0; k < 32; k += 8) {
        fill(all(bucket), 0);
        for (int i = 0; i < n; i++)
            bucket[(b[i].fi.se >> k) & 255]++;
        for (int i = 1; i < 256; i++)
            bucket[i] += bucket[i - 1];

        vector<pair<pair<int, int>, int>> aux(n);
        for (int i = n - 1; i >= 0; i--) {
            aux[bucket[(b[i].fi.se >> k) & 255] - 1] = b[i];
            bucket[(b[i].fi.se >> k) & 255]--;
        }
        b = aux;
    }

    for (int k = 0; k < 32; k += 8) {
        fill(all(bucket), 0);
        for (int i = 0; i < n; i++)
            bucket[(b[i].fi.fi >> k) & 255]++;
        for (int i = 1; i < 256; i++)
            bucket[i] += bucket[i - 1];

        vector<pair<pair<int, int>, int>> aux(n);
        for (int i = n - 1; i >= 0; i--) {
            aux[bucket[(b[i].fi.fi >> k) & 255] - 1] = b[i];
            bucket[(b[i].fi.fi >> k) & 255]--;
        }
        b = aux;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    string s;
    cin >> s;
    s += '$';
    int n = size(s);
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
        vector<pair<pair<int, int>, int>> b(n);
        for (int i = 0; i < n; i++) b[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
        radix_sort(b);

        for (int i = 0; i < n; i++) p[i] = b[i].se;
        c[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            if (b[i].fi == b[i - 1].fi)
                c[p[i]] = c[p[i - 1]];
            else
                c[p[i]] = c[p[i - 1]] + 1;
        }
        k++;
    }

    // Answer
    for (int i = 0; i < n; i++)
        cout << p[i] << " ";

    return 0;
}

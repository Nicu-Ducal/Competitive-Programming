#include <bits/stdc++.h>
using namespace std;

template <typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
using i64 = long long int;

const int INF = INT_MAX, MOD = 1e9 + 7;
const double EPS = 1e-9, PI = acos(-1);
const int dx[] = {0, 0, 0, -1, 1, -1, 1, 1, -1};
const int dy[] = {0, -1, 1, 0, 0, -1, 1, -1, 1};

/**
 *  Author: Neeecu
 *  Data structure: Segment Tree (min)
 */
template<typename T>
struct min_segment_tree {
    vector<T> tree, lazy, arr;
    int n;

    void init(int l, int r, int pos) {
        if (l == r)
            tree[pos] = arr[l];
        else {
            int mid = l + (r - l) / 2;
            init(l, mid, 2 * pos + 1);
            init(mid + 1, r, 2 * pos + 2);
            tree[pos] = min(tree[2 * pos + 1], tree[2 * pos + 2]);
        }
    }

    min_segment_tree(vector<T> _arr) : arr(_arr), n(arr.size()) {
        tree.resize(4 * n);
        lazy.resize(4 * n, 0);
        init(0, n - 1, 0);
    }

    void add(int idx, T val) {
        _update(val, idx, idx, 0, n - 1, 0);
    }

    void add(int l, int r, T val) {
        _update(val, l, r, 0, n - 1, 0);
    }

    void update(int idx, T val) {
        _update(val - query(idx, idx), idx, idx, 0, n - 1, 0);
    }

    void _update(int val, int l, int r, int li, int ri, int pos) {
        if (lazy[pos] != 0) {
            tree[pos] += lazy[pos];
            if (li != ri) {
                lazy[2 * pos + 1] += lazy[pos];
                lazy[2 * pos + 2] += lazy[pos];
            }
            lazy[pos] = 0;
        }

        if (ri < l or r < li)
            return;
        else if (l <= li and ri <= r) {
            tree[pos] = val;
            if (li != ri) {
                lazy[2 * pos + 1] += val;
                lazy[2 * pos + 2] += val;
            }
        } else {
            int mi = li + (ri - li) / 2;
            _update(val, l, r, li, mi, 2 * pos + 1);
            _update(val, l, r, mi + 1, ri, 2 * pos + 2);
            tree[pos] = min(tree[2 * pos + 1], tree[2 * pos + 2]);
        }
    }

    T query(int l, int r) {
        return _query(l, r, 0, n - 1, 0);
    }

    T _query(int l, int r, int li, int ri, int pos) {
        if (lazy[pos] != 0) {
            tree[pos] += lazy[pos];
            if (li != ri) {
                lazy[2 * pos + 1] += lazy[pos];
                lazy[2 * pos + 2] += lazy[pos];
            }
            lazy[pos] = 0;
        }

        if (r < li or ri < l)
            return LLONG_MAX;
        else if (l <= li and ri <= r)
            return tree[pos];
        else {
            int mi = li + (ri - li) / 2;
            return min(_query(l, r, li, mi, 2 * pos + 1), _query(l, r, mi + 1, ri, 2 * pos + 2));
        }
    }

    int query_index(int l, int r) {
        return _query_index(l, r, 0, n - 1, 0).first;
    }

    pair<i64, int> _query_index(int l, int r, int li, int ri, int pos) {
        if (lazy[pos] != 0) {
            tree[pos] += lazy[pos];
            if (li != ri) {
                lazy[2 * pos + 1] += lazy[pos];
                lazy[2 * pos + 2] += lazy[pos];
            }
            lazy[pos] = 0;
        }

        if (r < li or ri < l)
            return {LLONG_MAX, INF};
        else if (l <= li and ri <= r and li == ri)
            return {li, tree[pos]};
        else {
            int mi = li + (ri - li) / 2;
            pair<i64, int> lo = _query_index(l, r, li, mi, 2 * pos + 1);
            pair<i64, int> hi = _query_index(l, r, mi + 1, ri, 2 * pos + 2);
            return ((lo.second <= hi.second) ? lo : hi);
        }
    }
};

struct Task {
    i64 id, pw, a, b;
    vector<pair<i64, i64>> ans;

    Task(int _id, int _pw, int _a, int _b) : id(_id), pw(_pw), a(_a), b(_b) {
        ans.resize(0);
    }

    bool operator<(const Task& other) const {
        if (other.b - other.a + 1 == this->b - this->a + 1)
            return pw < other.pw;
        else return ((b - a + 1) < (other.b - other.a + 1));
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    //ifstream cin("../input.txt");
    ifstream cin("../level4_5.in");
    ofstream cout("../answer.txt");

    i64 n, m, maxPow, maxBill, curBill = 0;
    cin >> maxPow >> maxBill;
    cin >> n;
    vector<i64> v(n), used(n, maxPow);
    for (int i = 0; i < n; i++) cin >> v[i];
    min_segment_tree<i64> seg(v);
    cin >> m;
    vector<Task> tasks;
    vector<vector<pair<i64, i64>>> ans(m + 1);
    for (int i = 0; i < m; i++) {
        i64 t, pw, a, b;
        cin >> t >> pw >> a >> b;
        tasks.push_back(Task(t, pw, a, b));
    }
    sort(tasks.begin(), tasks.end());
    for (int t = 0; t < m; t++) {
        auto cur = tasks[t];
        while (cur.pw > 0) {
            i64 idx = seg.query_index(cur.a, cur.b);
            i64 l = 0, r = min(cur.pw + 1, used[idx] + 1);
            while (l < r) {
                i64 mid = (l + r) >> 1;
                if (mid * v[idx] + curBill <= maxBill) l = mid + 1;
                else r = mid;
            }
            ans[cur.id].push_back({idx, l - 1});
            cur.pw -= (l - 1);
            used[idx] -= (l - 1);
            curBill += (l - 1) * v[idx];
            if (used[idx] == 0) seg.update(idx, INF);
        }
    }
    cout << m << "\n";
    for (int task = 1; task <= m; task++) {
        cout << task << " ";
        for (auto it: ans[task]) cout << it.first << " " << it.second << " ";
        cout << "\n";
    }
    //cout << curBill;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

template <typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
using i64 = long long int;

const int INF = INT_MAX, MOD = 1e9 + 7;
const double EPS = 1e-9, PI = acos(-1);
const int dx[] = {0, 0, 0, -1, 1, -1, 1, 1, -1};
const int dy[] = {0, -1, 1, 0, 0, -1, 1, -1, 1};

//bool compare_pair(pair<int, int> &p1, pair<int, int> &p2) {
//  return (p2.second - p2.first > p1.second - p1.first);
//}
//
///**
// *  Author: Neeecu
// *  Data structure: Segment Tree (max)
// */
//template<typename T>
//struct max_segment_tree {
//  vector<T> arr;
//  vector<pair<int, int>> tree, lazy;
//  int n;
//
//  void init(int l, int r, int pos) {
//    if (l == r)
//      tree[pos] = {l, r};
//    else {
//      int mid = l + (r - l) / 2;
//      init(l, mid, 2 * pos + 1);
//      init(mid + 1, r, 2 * pos + 2);
//      pair<int, int> lf = tree[2 * pos + 1];
//      pair<int, int> rg = tree[2 * pos + 2];
//      tree[pos] = {1, 1};
//    }
//  }
//
//  max_segment_tree(vector<T> _arr) : arr(_arr), n(arr.size()) {
//    tree.resize(4 * n);
//    lazy.resize(4 * n, {-1, -1});
//    init(0, n - 1, 0);
//  }
//
//  void add(int idx, T val) {
//    _update(val, idx, idx, 0, n - 1, 0);
//  }
//
//  void add(int l, int r, T val) {
//    _update(val, l, r, 0, n - 1, 0);
//  }
//
//  void update(int idx, T val) {
//    _update(val - query(idx, idx), idx, idx, 0, n - 1, 0);
//  }
//
//  void _update(int val, int l, int r, int li, int ri, int pos) {
//    if (lazy[pos] != make_pair(-1, -1)) {
//      tree[pos] = (compare_pair(tree[pos], lazy[pos]) ? lazy[pos] : tree[pos]);
//      if (li != ri) {
//        lazy[2 * pos + 1] = (compare_pair(lazy[2 * pos + 1], lazy[pos]) ? lazy[pos] : lazy[2 * pos + 1]);
//        lazy[2 * pos + 2] = (compare_pair(lazy[2 * pos + 2], lazy[pos]) ? lazy[pos] : lazy[2 * pos + 2]);
//      }
//      lazy[pos] = {-1, -1};
//    }
//
//    if (ri < l or r < li)
//      return;
//    else if (l <= li and ri <= r) {
//      tree[pos] = {l, r};
//      if (li != ri) {
//        lazy[2 * pos + 1] = (compare_pair(lazy[2 * pos + 1], tree[pos]) ? tree[pos] : lazy[2 * pos + 1]);
//        lazy[2 * pos + 2] = (compare_pair(tree[pos], lazy[pos]) ? lazy[pos] : tree[pos]);
//      }
//    } else {
//      int mi = li + (ri - li) / 2;
//      _update(val, l, r, li, mi, 2 * pos + 1);
//      _update(val, l, r, mi + 1, ri, 2 * pos + 2);
//      tree[pos] = max(tree[2 * pos + 1], tree[2 * pos + 2]);
//    }
//  }
//
//  T query(int l, int r) {
//    return _query(l, r, 0, n - 1, 0);
//  }
//
//  T _query(int l, int r, int li, int ri, int pos) {
//    if (lazy[pos] != 0) {
//      tree[pos] += lazy[pos];
//      if (li != ri) {
//        lazy[2 * pos + 1] += lazy[pos];
//        lazy[2 * pos + 2] += lazy[pos];
//      }
//      lazy[pos] = 0;
//    }
//
//    if (r < li or ri < l)
//      return LLONG_MIN;
//    else if (l <= li and ri <= r)
//      return tree[pos];
//    else {
//      int mi = li + (ri - li) / 2;
//      return max(_query(l, r, li, mi, 2 * pos + 1), _query(l, r, mi + 1, ri, 2 * pos + 2));
//    }
//  }
//
//  void friend1(int idx) {
//
//  }
//};


void update(vector<int> &a, int i, int val) {
  if (val == 1 and a[i + 1] == 0) a[i + 1] += val;
  else if (val == -1 and i <= a.size() - 2 and a[i + 2] == 0) a[i + 1] += val;
  a[i] += val;
}

int query(vector<int> &v, int a, int b) {
  int longest = 1;
  int fi = a, li = a;
  while (fi <= b) {
    if (v[fi] == 0) fi++;
    else if (v[fi] == 1) {
      li = fi;
      while (li < b and v[li + 1] == 1) li++;
      longest = max(longest, li - fi + 1);
      fi = li;
    }
  }
  return longest;
}


int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  int N, Q; cin >> N >> Q;
  vector<int> a(N + 1, 0);
  while (Q--) {
    int qu, x, y, i; cin >> qu;
    // max_segment_tree<int> seg(vector<int>(N, 1));

    switch (qu) {
      case 1:
        cin >> i;
        update(a, i, 1);
        break;
      case 2:
        update(a, i, -1);
        cin >> i;
        break;
      case 3:
        cin >> x >> y;
        cout << query(a, x, y) << '\n';
    }
  }

  return 0;
}

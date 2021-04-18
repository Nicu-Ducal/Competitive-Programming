#include <bits/stdc++.h>
using namespace std;

template <typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
using i64 = long long int;

const int INF = INT_MAX, MOD = 1e9 + 7;
const double EPS = 1e-9, PI = acos(-1);
const int dx[] = {0, 0, 0, -1, 1, -1, 1, 1, -1};
const int dy[] = {0, -1, 1, 0, 0, -1, 1, -1, 1};

struct Point {
  double x, y;

  Point(double x, double y) : x(x), y(y) {}

  bool operator<(const Point& other) const {
    return (x < other.x or (x == other.x and y < other.y));
  }
};

struct Hull {
  vector<Point> points, hull;
  int n;

  Hull(int n = 0) {
    init(n);
  }

  void init(int _n) {
    n = _n;
    points.assign(n, Point(0, 0));
  }

  bool clockwise(const Point& a, const Point& b, const Point& c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
  }

  bool counter_clockwise(const Point& a, const Point& b, const Point& c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
  }

  /// Algorithm from CP-Algorithms that divides the set of points into two sets
  void GrahamScanCP() {
    sort(points.begin(), points.end());

    Point leftmost = points[0], rightmost = points.back();
    vector<Point> up, down;
    up.push_back(leftmost);
    down.push_back(leftmost);

    for (int i = 1; i < (int) points.size(); i++) {
      if (i == (int) points.size() - 1 or clockwise(leftmost, points[i], rightmost)) {
        while (up.size() >= 2 and not clockwise(up[up.size() - 2], up[up.size() - 1], points[i]))
          up.pop_back();
        up.push_back(points[i]);
      }
      if (i == (int) points.size() - 1 or counter_clockwise(leftmost, points[i], rightmost)) {
        while (down.size() >= 2 and not counter_clockwise(down[down.size() - 2], down[down.size() - 1], points[i]))
          down.pop_back();
        down.push_back(points[i]);
      }
    }

    for (auto pt: down)
      hull.push_back(pt);
    for (int i = (int) up.size() - 2; i > 0; i--)
      hull.push_back(up[i]);
  }

  /// InfoArena Idea
  void GrahamScan() {
    /// Select the leftmost point in the array and then sort the points based on the angle it makes with this point
    int leftmost = 0;
    for (int i = 1; i < n; i++) {
      if (points[i] < points[leftmost])
        leftmost = i;
    }
    swap(points[0], points[leftmost]);
    sort(points.begin() + 1, points.end(), [&](const Point& a, const Point& b) {
      return counter_clockwise(points[0], a, b);
    });

    /// Traverse the array and find the points that are only counter-clockwise with the two previous ones
    vector<Point> stk;
    stk.push_back(points[0]);
    stk.push_back(points[1]);

    for (int i = 2; i < n; i++) {
      while (stk.size() >= 2 and clockwise(stk[stk.size() - 2], stk[stk.size() - 1], points[i]))
        stk.pop_back();
      stk.push_back(points[i]);
    }
    hull = stk;
  }
};


int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  ifstream cin("infasuratoare.in");
  ofstream cout("infasuratoare.out");

  int n; cin >> n;
  double x, y;
  Hull hull(n);
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    hull.points[i] = Point(x, y);
  }
  hull.GrahamScan();
  cout << hull.hull.size() << "\n";
  cout << fixed << setprecision(15);
  for (auto pt: hull.hull)
     cout << pt.x << " " << pt.y << "\n";

  return 0;
}


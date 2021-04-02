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
const double EPS = 1e-9;
const double PI = acos(-1);

ll t;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    cin >> t;
    while (t--) {
        string n, ans = "0";
        ll s;
        cin >> n >> s;
        ll sum = 0;
        ans += n;
        for (int i = 0; i < len(n); i++) {
            sum += n[i] - '0';
        }
        //cout << n << " " << sum << "\n";

        if (sum <= s) {
            cout << "0\n";
            continue;
        }

        for (int i = len(ans) - 2; i >= 0; i--) {
            if (ans[i] == '0' and ans[i + 1] == '0') {
                continue;
            } else if (ans[i] == '9') {
                sum -= (ans[i + 1] - '0');
                ans[i + 1] = '0';
                ll j = i;
                while (j >= 0 and ans[j] == '9') {
                    sum -= 9;
                    ans[j] = '0';
                    j--;
                }
                ans[j]++;
                sum++;
            } else {
                sum -= (ans[i + 1] - '0') - 1;
                ans[i + 1] = '0';
                ans[i]++;

                if (sum <= s) {
                    break;
                }
            }
            //cout << i << " " << sum << " " << ans << "\n";
        }

        int idx = 0;
        while (ans[idx] == '0')
            idx++;
        ans = ans.substr(idx, len(ans) - idx);
        ans = findDiff(ans, n);
        idx = 0;
        while (ans[idx] == '0')
            idx++;
        ans = ans.substr(idx, len(ans) - idx);
        cout <<  ans << "\n";
    }

    return 0;
}

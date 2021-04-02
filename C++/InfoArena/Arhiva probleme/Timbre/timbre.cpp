#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define pll pair<long long, long long>
#define pii pair<int, int>
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

int n, m, k, x, cost, ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ifstream cin("timbre.in");
    ofstream cout("timbre.out");

    cin >> n >> m >> k;
    vector<pii> t;
    for (int i = 0; i < m; i++){
        cin >> x >> cost;
        t.pb({x, cost});
    }
    sort(all(t));

    priority_queue<int, vector<int>, greater<int>> pq;
    int i = m - 1;
    while (n > 0){
        while (i >= 0 and t[i].fi >= n){
            pq.push(t[i].se);
            i--;
        }
        n -= k;
        ans += pq.top();
        pq.pop();
    }
    cout << ans;

    return 0;
}

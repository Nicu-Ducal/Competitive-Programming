#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << "\n"
#define all(x) (x).begin(),(x).end()
#define len length()
#define sz size()
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>

using ull = unsigned long long;
using ll = long long;
using namespace std;

const int MAXN = 1e6 + 5;
const int INF = INT_MAX;
ll t, n, m, st, timp;
priority_queue<ll, vector<ll>, greater<ll>> disp;
priority_queue<pll, vector<pll>, greater<pll>> task;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("proc2.in");
    ofstream cout("proc2.out");

    cin >> n >> m;
    for (ll i = 1; i <= n; i++){
        disp.push(i);
    }
    for (ll i = 1; i <= m; i++){
        cin >> st >> timp;
        while(!task.empty() and task.top().fi <= st){
            disp.push(task.top().se);
            task.pop();
        }
        cout << disp.top() << "\n";
        task.emplace(st + timp, disp.top());
        disp.pop();
    }

    return 0;
}

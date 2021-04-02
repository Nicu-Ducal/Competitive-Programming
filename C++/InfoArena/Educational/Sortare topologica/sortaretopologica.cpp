#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("sortaret.in");
    ofstream cout("sortaret.out");

    ll a, b, n, m;
    cin >> n >> m;

    vector <ll> g[n + 1];
    ll pred[n + 1];
    for (ll i = 0; i <= n; i++)
        pred[i] = 0;

    for (ll i = 0; i < m; i++)
    {
        cin >> a >> b;
        g[a].pb(b);
        pred[b]++;
    }

    vector <ll> zero;
    for (ll i = 1; i <= n; i++)
        if (pred[i] == 0)
            zero.pb(i);

    queue <ll> q;
    vector <ll> st;
    for (auto x: zero)
    {
        q.push(x);
        st.pb(x);
        while (!q.empty())
        {
            ll curr = q.front();
            q.pop();
            for (auto succ: g[curr])
            {
                pred[succ]--;
                if (pred[succ] == 0)
                {
                     st.pb(succ);
                     q.push(succ);
                }
            }
        }
    }

    for (auto x: st)
        cout << x << " ";

    return 0;
}

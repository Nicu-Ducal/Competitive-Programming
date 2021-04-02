#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define len length()
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll q, n, m, a, b, inp[100005], aib[100005];

void create(ll idx){
    if (idx >= n)
        return;

    ll now = idx + 1;
    while(now <= n){
        aib[now] += inp[idx];
        now += (-now & now);
    }
    create(idx + 1);
}

void update(ll idx, ll b){
    ll now = idx + 1;
    while(now <= n){
        aib[now] += b;
        now += (-now & now);
    }
}

ll search(ll val){
    if (val == 0)
        return -1;
    int pos = 0, pw = 1;
    while (pw < n)
        pw <<= 1;
    while (pw > 0){
        if (pos + pw <= n and aib[pos + pw] <= val){
            pos += pw;
            val -= aib[pos];
        }
        pw >>= 1;
    }

    if (val) return -1;
    return pos;
}

ll sum(ll idx){
    ll ans = 0;
    ll now = idx + 1;
    while(now){
        ans += aib[now];
        now -= (-now & now);
    }
    return ans;
}

ll query(ll a, ll b){
    return sum(b) - sum(a - 1);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("aib.in");
    ofstream cout("aib.out");

    aib[0] = 0;
    cin >> n >> m;
    for (ll i = 0; i < n; i++)
        cin >> inp[i];

    create(0);

    /*for (int i = 0; i <= n; i++) cout << aib[i] << " ";
    cout << "\n";*/

    while(m--){
        cin >> q;
        if (q == 0){
            cin >> a >> b;
            inp[a - 1] += b;
            update(a - 1, b);
        }

        else if (q == 1){
            cin >> a >> b;
            --a, --b;
            cout << query(a, b) << "\n";
        }
        else if (q == 2){
            cin >> a;
            cout << search(a) << "\n";
        }
    }

    return 0;
}

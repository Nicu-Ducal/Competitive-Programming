#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll n, m, a, b, c, inp[100005], arb[500020];

void create(ll arb[], ll inp[], ll low, ll high, ll pos){
    if (low == high){
        arb[pos] = inp[low];
        return;
    }

    ll mid = low + (high - low) / 2;
    create(arb, inp, low, mid, 2 * pos + 1);
    create(arb, inp, mid + 1, high, 2 * pos + 2);
    arb[pos] = max(arb[2 * pos + 1], arb[2 * pos + 2]);
}

int query(ll idx, ll low, ll high, ll a, ll b){
    if (a <= low and high <= b)
        return arb[idx];

    if (high < a or b < low)
        return 0;

    ll mid = low + (high - low) / 2;
    return max(query(2 * idx + 1, low, mid, a, b), query(2 * idx + 2, mid + 1, high, a, b));
}

void update(ll idx, ll low, ll high, ll pos){
    if (pos > high or pos < low)
        return;

    if (low == high)
        arb[idx] = inp[pos];
    else{
        ll mid = low + (high - low) / 2;
        update(2 * idx + 1, low, mid, pos);
        update(2 * idx + 2, mid + 1, high, pos);
        arb[idx] = max(arb[2 * idx + 1], arb[2 * idx + 2]);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("arbint.in");
    ofstream cout("arbint.out");

    cin >> n >> m;
    for (ll i = 0; i < n; i++)
        cin >> inp[i];

    int dim = log2(2 * n - 1) + 1;
    dim = (1 << dim) - 1;

    create(arb, inp, 0, n - 1, 0);

    while(m--){
        cin >> c >> a >> b;
        if (c == 0)
            cout << query(0, 0, n - 1, a - 1, b - 1) << "\n";
        else{
            a--;
            inp[a] = b;
            update(0, 0, n - 1, a);
        }
    }

    return 0;
}

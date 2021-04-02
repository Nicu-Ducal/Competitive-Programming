#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll n, k;

int quickselect(vector<ll> &v, int k, int lo, int hi){
    if (lo == hi)
        return v[lo];
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distribution(lo, hi);

    // Partitionare
    int piv = distribution(rng);
    swap(v[piv], v[hi]);
    int i = lo;
    for (int j = lo; j < hi; j++){
        if (v[j] <= v[hi]){
            swap(v[i], v[j]);
            i++;
        }
    }
    swap(v[i], v[hi]);
    piv = i;
    int idx = piv - lo + 1;
    if (k == idx)
        return v[piv];
    else if (k < idx)
        return quickselect(v, k, lo, piv - 1);
    else
        return quickselect(v, k - idx, piv + 1, hi);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("sdo.in");
    ofstream cout("sdo.out");

    cin >> n >> k;
    vector <ll> a(n, 0);
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    cout << quickselect(a, k, 0, n - 1);
    //nth_element(a.begin(), a.begin() + k - 1, a.end());
    //cout << a[k - 1];
    return 0;
}

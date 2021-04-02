#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

const ll maxN = 200005;
ll n, a[maxN], ans = -1;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("logik.in");
    ofstream cout("logik.out");

    cin >> n;
    for (ll i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] % 2 == 0)
            ans &= a[i];
        else if (a[i] % 2 == 1 && a[i - 1] % 2 == 1 && i > 0)
            ans &= (a[i] | a[i - 1]);
    }

    cout << ans;

    return 0;
}

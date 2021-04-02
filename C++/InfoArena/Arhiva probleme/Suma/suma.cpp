#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("suma.in");
    ofstream cout("suma.out");

    ll n, p;
    cin >> n >> p;

    cout << ((((n - 1) % p) * (n % p) * ((n + 1) % p)) / 3) % p;

    return 0;
}

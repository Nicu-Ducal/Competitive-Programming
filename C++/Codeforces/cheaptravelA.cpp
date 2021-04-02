#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    int a, b, n, m;
    cin >> n >> m >> a >> b;
    cout << min((n / m) * b + (n % m) * a, min(((n / m) + 1) * b, n * a));

    return 0;
}

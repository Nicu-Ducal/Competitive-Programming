#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    ll n;
    cin >> n;
    double sum = 0;
    while (n)
    {
        sum += (double) 1 / n;
        n--;
    }
    cout.precision(12);
    cout << fixed << sum << "\n";
    return 0;
}

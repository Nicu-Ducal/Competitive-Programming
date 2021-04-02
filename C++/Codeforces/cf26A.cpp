#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll n, num;
bool ciur[10005];
set <ll> factors;

void create(){
    for (ll i = 2; i < 10005; i++)
        ciur[i] = 1;
    for (ll i = 2; i < 10005; i++)
        for (ll j = 2 * i; j < 10005; j += i)
            ciur[j] = 0;
}

ll nextPrime(ll p){
    bool ok = 0;
    while(!ok){
        if (p == 2){
            p++;
            ok = 1;
        }
        else{
            p += 2;
            if (ciur[p])
                ok = 1;
        }
    }
    return p;
}

bool check(ll n){
    if (n < 6)
        return 0;
    ll p = 2;
    while (n > 1){
        if (n % p == 0){
            factors.insert(p);
            if (factors.size() > 2){
                factors.clear();
                return 0;
            }
            while (n % p == 0){
                n /= p;
            }
        }
        p = nextPrime(p);
    }
    if (factors.size() == 2){
        factors.clear();
        return 1;
    }
    factors.clear();
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    create();

    cin >> n;
    for (ll i = 1; i <= n; i++)
        num += check(i);
    cout << num;

    return 0;
}

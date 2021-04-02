#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

bool ciur[1000005];
void create(){
    for (ll i = 2; i < 1000005; i++)
        ciur[i] = 1;
    for (ll i = 2; i < 1000005; i++)
        if (ciur[i])
            for(ll j = 2*i; j < 1000005; j += i)
                ciur[j] = 0;
}

ll nextPrim(ll p){
    if (p % 2 == 0)
        p++;
    else
        p += 2;
    while(1){
        if (ciur[p])
            return p;
        p += 2;
    }
}

bool verificare(ll x){
    ll p = 2, put = 0;
    while(1){
        if (x % p == 0){
            while (x % p == 0){
                put++;
                x /= p;
            }
            if (x != 1 || (x == 1 && put == 1))
                return 0;
            return 1;
        }
        else
            p = nextPrim(p);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("asi.in");
    ofstream cout("asi.out");

    create();
    ll q, a, b, cnt;
    cin >> q;
    while(q--){
        cin >> a >> b;
        cnt = 0;
        for (ll i = a; i <= b; i++){
            if (verificare(i))
                cnt++;
        }
        cout << cnt << "\n";
    }

    return 0;
}

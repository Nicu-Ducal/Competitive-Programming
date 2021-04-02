#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

const ll maxPut = 1000005;
ll t, st, dr;
bool ciur[maxPut];
vector<ll> puteri;

void create(){
    for (ll i = 2; i < 1000005; i++)
        ciur[i] = 1;
    for (ll i = 2; i < 1000005; i++)
        if (ciur[i]){
            for (ll j = 2 * i; j < 1000005; j += i)
                ciur[j] = 0;
            for (ll j = i * i; j <= maxPut * maxPut; j *= i)
                puteri.push_back(j);
            }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("asi.in");
    ofstream cout("asi.out");

    create();
    sort(all(puteri));

    cin >> t;
    while(t--){
        cin >> st >> dr;

        cout << upper_bound(all(puteri), dr) - lower_bound(all(puteri), st) << "\n";
    }

    return 0;
}

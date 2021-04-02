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
            for(ll j = 2*i; j < 1000005; j++)
                ciur[j] = 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("asi.in");
    ofstream cout("asi.out");

    create();
    ll q, a, b, n, cnt, a1,b1;
    cin >> q;
    while(q--){
        cin >> a >> b;
        cnt = 0;
        n = 2;
        while(1){
            a1 = pow(a, 1.0/n);
            b1 = pow(b, 1.0/n);
            //cout << a1 << " " << b1 << "\n";
            if (a1 == 1 && b1 == 1){
                if (pow(a1, n) == a && ciur[a1])
                    cnt++;
                break;
            }

            ll temp = 0;

            if (pow(a1, n) == a && ciur[a1])
                temp++;
            for (ll i = a1 + 1; i <= b1; i++)
                if (ciur[i])
                    temp++;

            cnt += temp;
            n++;
        }

        cout << cnt << "\n";
    }

    return 0;
}

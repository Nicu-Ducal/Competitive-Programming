#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll n, m, k;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("trenul.in");
    ofstream cout("trenul.out");

    cin >> n >> m;
    ll poz1 = 1, poz2 = n - 1;
    while(m--){
        cin >> k;
        switch (k){
            case 1:
                cout << poz1++ << "\n";
                break;
            case 2:
                cout << poz2 << ' ' << poz2 + 1 << "\n";
                poz2 -= 2;
                break;
            case 3:
                cout << poz1 << ' ' << poz1 + 1 << ' ' << poz1 + 2 << "\n";
                poz1 += 3;
                break;
        }
    }

    return 0;
}

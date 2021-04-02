#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ll k, r;
    cin >> k >> r;
    if ((k % 10) & 1 == 0 && (r & 1)){
        cout << 10;
        return 0;
    }
    for (int i = 1; i < 10; i++)
        if ((k * i - r) % 10 == 0 || (k * i) % 10 == 0){
            cout << i;
            break;
        }

    return 0;
}

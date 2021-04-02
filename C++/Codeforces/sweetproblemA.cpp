#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll t, c[3];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> t;
    while(t--)
    {
        cin >> c[0] >> c[1] >> c[2];
        ll req = 0;
        sort(c, c + 3);
        if (c[2] >= c[0] + c[1])
            cout << c[0] + c[1] << "\n";
        else
            cout << (c[0] + c[1] + c[2]) / 2 << "\n";
    }
    return 0;
}

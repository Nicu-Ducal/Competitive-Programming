#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll t, a, b, x, y;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        if (a == b)
            cout << "0\n";
        else if (a < b)
            if ((b - a) & 1)
                cout << "1\n";
            else
                cout << "2\n";
        else
            if ((b - a) & 1)
                cout << "2\n";
            else
                cout << "1\n";
    }

    return 0;
}

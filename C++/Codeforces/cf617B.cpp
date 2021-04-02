#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll s, t;

ll maxim(ll s)
{
    if (s >= 0 && s <= 9)
        return s;
    return (s - s % 10) + maxim(s - (s - s % 10) + s / 10);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> t;
    while(t--)
    {
        cin >> s;
        cout << maxim(s) << "\n";
    }

    return 0;
}

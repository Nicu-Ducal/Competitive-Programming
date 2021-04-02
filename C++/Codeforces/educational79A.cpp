#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll t, a[3];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> t;
    while(t--)
    {
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);
        if (a[2] > a[0] + a[1] + 1)
        {
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
    }
    return 0;
}

#include <bits/stdc++.h>
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll t, x, y;

int main(){
ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

cin >> t;
while (t--)
{
    cin >> x >> y;
    if (x >= y || x == 2 && y == 3)
    {
        cout << "YES\n";
        continue;
    }
    if (x == 1 || x == 2 || x == 3)
    {
        cout << "NO\n";
        continue;
    }
    cout << "YES\n";
}

return 0;
}

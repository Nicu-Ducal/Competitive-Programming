#include <bits/stdc++.h>
typedef unsigned int ui;
typedef long long ll;
using namespace std;

ll t,a, b, x;

int main(){
ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

cin >> t;

while(t--)
{
    cin >> a >> b;
    if (a > b) swap(a, b);

    if (2 * a >= b && (a + b) % 3 == 0)
    {
        cout <<"YES\n";
        continue;
    }
    cout << "NO\n";
}


return 0;
}

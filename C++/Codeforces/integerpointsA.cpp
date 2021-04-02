#include <bits/stdc++.h>
typedef unsigned int ui;
typedef long long ll;
using namespace std;

int t, n, m;
ll p,q, p0,p1,q0,q1;
int pt;

int main(){
ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

cin >> t;
while (t--)
{
    pt = p1 = p0 = q1 = q0 = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p;
        if (p % 2) p1++;
        else p0++;
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> q;
        if (q % 2) q1++;
        else q0++;
    }

    cout << p1 * q1 + p0 * q0 << "\n";
}

return 0;
}

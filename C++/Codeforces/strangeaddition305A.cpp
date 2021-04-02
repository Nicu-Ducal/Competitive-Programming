#include <bits/stdc++.h>
#define pb push_back
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

int n, a[105], num;
vector <int> add;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n;

    bool z0 = 1, z100 = 1, z2 = 1, z3 = 1, z4 = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 0 || a[i] == 100)
        {
            if (a[i] == 0 && z0)
            {
                add.pb(a[i]);
                z0 = 0;
                continue;
            }
            else if (a[i] == 100 && z100)
            {
                add.pb(a[i]);
                z100 = 0;
                continue;
            }
        }
        else if (a[i] > 0 && a[i] < 10 && z2)
        {
            add.pb(a[i]);
            z2 = 0;
            continue;
        }
        else if (a[i] >= 10 && a[i] < 100 && (a[i] % 10 == 0) && z3)
        {
            add.pb(a[i]);
            z3 = 0;
            continue;
        }
        else if (z4)
        {
            num = a[i];
            z4 = 0;
            continue;
        }
    }

    if (z2 && z3 && !z4)
    {
        add.pb(num);
    }

    cout << add.size() << "\n";
    for (int i = 0; i < add.size(); i++)
        cout << add[i] << " ";

    return 0;
}

#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

int n, c, ans, sol[20];
bool col[20], dpr[40], dse[40];

ifstream in("regine.in");
ofstream out("regine.out");

void Dame(int k)
{
    if (k == n + 1)
    {
        if (c < 3)
        {
            for (int i = 1; i <= n; i++)
                out << sol[i] << ' ';
            out << "\n";
            c++;
        }
        ans++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (col[i] || dse[k + i] || dpr[n - i + 1 + k])
            continue;

        sol[k] = i;
        col[i] = dpr[n - i + 1 + k] = dse[k + i] = 1;

        Dame(k + 1);

        col[i] = dpr[n - i + 1 + k] = dse[i + k] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    in >> n;
    ans = 0;
    c = 0;
    Dame(1);
    out << ans;

    return 0;
}

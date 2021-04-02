#include <bits/stdc++.h>
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

int n, tab[20], sol = 0;
bool col[20], dp[50], ds[50];

ifstream in("damesah.in");
ofstream out("damesah.out");

void afisare()
{
    for (int i = 1; i <= n; i++)
    {
        out << tab[i] << " ";
    }
    out << "\n";
}

void dame(int k)
{
    if (k == n + 1)
    {
        if (sol == 0)
            afisare();
        sol++;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (col[i] || dp[n - i + 1 + k] || ds[i + k])
            continue;

        tab[k] = i;
        col[i] = dp[n - i + 1 + k] = ds[i + k] = 1;

        dame(k + 1);

        col[i] = dp[n - i + 1 + k] = ds[i + k] = 0;
    }
}

int main(){
//ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

in >> n;

dame(1);

out << sol;
return 0;
}


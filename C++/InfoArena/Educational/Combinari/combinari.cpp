#include <bits/stdc++.h>
typedef unsigned int ui;
typedef long long ll;
using namespace std;

ifstream fin("combinari.in");
ofstream fout("combinari.out");

int n, k, c[20];

bool valid(int m)
{
    for (int i = 1; i < m - 1; i++)
    {
        if (c[i] == c[k]) return 0;
    }
    return 1;
}

bool solutie(int m)
{
    if (m == k) return 1;
    return 0;
}

void afisare(int m)
{
    for (int i = 1; i <= m; i++)
    {
        fout << c[i] << " ";
    }
    fout << "\n";
}

void Combinari(int m)
{
    c[0] = 0;
    for (int i = c[m-1]+1; i <= n; i++)
    {
        c[m] = i;
        if (valid(m))
        {
            if (solutie(m)) afisare(m);
            else Combinari(m + 1);
        }
    }
}


int main(){

fin >> n >> k;

Combinari(1);

return 0;
}

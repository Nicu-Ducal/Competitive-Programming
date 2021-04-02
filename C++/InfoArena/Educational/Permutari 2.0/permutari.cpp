#include <bits/stdc++.h>
typedef unsigned int ui;
typedef long long ll;
using namespace std;

int n, p[10];

ifstream in("permutari.in");
ofstream out("permutari.out");
//ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

bool valid(int k)
{
    for (int i = 1; i <= k - 1; i++)
    {
        if (p[k] == p[i]) return 0;
    }
    return 1;
}

bool solutie(int k)
{
    if (k == n) return 1;
    return 0;
}

void afisare(int k)
{
    for (int i = 1; i <= n; i++)
    {
        out << p[i] << " ";
    }
    out << "\n";
}


void Permutare(int k)
{
    for (int i = 1; i <= n; i++)
    {
        p[k] = i;
        if (valid(k))
        {
            if(solutie(k)) afisare(k);
            else Permutare(k+1);
        }
    }
}

int main(){


in >> n;

Permutare(1);

return 0;
}

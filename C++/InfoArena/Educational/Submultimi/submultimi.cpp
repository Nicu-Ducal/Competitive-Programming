#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ifstream in("submultimi.in");
ofstream out("submultimi.out");

int n, sub[20];

void Afisare(int k)
{
    for (int i = 1; i <= k; i++)
        out << sub[i] << " ";
    out << "\n";
}

void Submultimi(int k)
{
    for (int i = sub[k - 1] + 1; i <= n; i++)
    {
        sub[k] = i;
        Afisare(k);
        Submultimi(k + 1);
    }
}

int main(){
    //ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    in >> n;
    Submultimi(1);

    return 0;
}

#include <bits/stdc++.h>
#define ull unsigned long int
#define ll long long
using namespace std;

const ll m = 1999999973;

ll ridicare_la_putere(ll N, ll P){
    if (P == 0){
        return 1;
    }
    else if (P == 1){
        return N%m;
    }
    else if (P % 2 == 0){
        return ridicare_la_putere((N*N)%m, P/2)%m;
    }
    else if (P % 2 == 1){
        return (N%m)*ridicare_la_putere((N*N)%m, (P-1)/2)%m;
    }
}

int main(){

ifstream cin("lgput.in");
ofstream cout("lgput.out");

ll N, P;
cin >> N >> P;


cout << ridicare_la_putere(N,P);

return 0;
}

#include <bits/stdc++.h>
typedef unsigned int ui;
typedef long long ll;
using namespace std;

int K;
bool ciur[2000010];
ll prim[100010];
void ciurSolv()
{
    ll j = 0;
    ciur[0] = 0;
    ciur[1] = 0;
    for (ll i = 2; i < 2000010; i++)
    {
        ciur[i] = 1;
    }
    for (ll i = 2; i < 2000010; i++)
    {
        if (ciur[i])
        {
            prim[j] = i;
            j++;
            for (ll m = 2*i; m < 2000010; m += i)
            {
                ciur[m] = 0;
            }
        }
    }
}

int main(){
ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
ifstream cin("prim.in");
ofstream cout("prim.out");

cin >> K;

ciurSolv();

ll N = prim[K]*prim[K];

cout << N;

return 0;
}

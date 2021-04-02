#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("alfanumeric.in");
    ofstream cout("alfanumeric.out");

    ll n;
    ll sumacif = 0;
    cin >> n;

    char curr;
    while (cin >> curr)
    {
        if (curr >= '0' && curr <= '9')
            sumacif += curr - 48;
        else if (curr >= 'a' && curr <= 'z')
            cout << (char)(curr - 32);
        else if (curr >= 'A' && curr <= 'Z')
            cout << curr;
    }
    cout << "\n" << sumacif;

    return 0;
}

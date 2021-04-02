#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    int n;
    cin >> n;
    int x = 0;
    string s;
    while (n--)
    {
        cin >> s;
        if (s == "X++" || s == "++X")
            x++;
        else
            x--;
    }
    cout << x;
    return 0;
}

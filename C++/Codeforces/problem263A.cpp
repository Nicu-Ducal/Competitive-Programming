#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    int io, jo, n;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++){
            cin >> n;
            if (n == 1){
                io = i;
                jo = j;
            }
        }
    cout << abs(io - 2) + abs(jo - 2);

    return 0;
}

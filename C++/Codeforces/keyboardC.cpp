#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, k;
string s;

int main(){

cin >> n >> k >> s;
char l[k];
for (ll i = 0; i < k; i++) cin >> l[i];

ll tot = 0;
ll curr = 0;
bool flag;

for (ll i = 0; i < n; i++){
    flag = 1;
    for (ll j = 0; j < k; j++)
    {
        if (s[i] == l[j])
        {
            curr++;
            flag = 0;
            break;
        }
    }
    if (flag) {
    tot += ((curr + 1) * curr) / 2;
    curr = 0;
    }
}
tot += ((curr + 1) * curr) / 2;

cout << tot;

return 0;
}

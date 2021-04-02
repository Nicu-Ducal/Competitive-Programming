#include <bits/stdc++.h>
typedef unsigned int ui;
typedef long long ll;
using namespace std;

ll n, a, m;

int main(){
ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
//ifstream cin(".in");
//ofstream cout(".out");

cin >> n >> m >> a;

ll l1, l2;
if (n % a) l1 = n / a + 1;
else l1 = n / a;
if (m % a) l2 = m / a + 1;
else l2 = m / a;

cout << l1 * l2;

return 0;
}

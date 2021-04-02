#include <bits/stdc++.h>
typedef unsigned int ui;
typedef long long ll;
using namespace std;

int t,n,x,a,b;

int main(){
ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();
//ifstream cin(".in");
//ofstream cout(".out");

cin >> t;

for (int i = 0; i < t; i++)
{
    cin >> n >> x >> a >> b;
        cout << min(n - 1, abs(a - b) + x) << "\n";
}

return 0;
}

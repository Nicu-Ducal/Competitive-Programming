#include <bits/stdc++.h>
using namespace std;

int t, a, b, c;

void euclid(int a, int b, int &d, int &x, int &y){
    if(b == 0){
        d = a;
        x = 1;
        y = 0;
    }
    else{
        int x0, y0;
        euclid(b, a % b, d, x0, y0);
        x = y0;
        y = x0 - (a / b) * y0;
    }
}

int main(){
ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
ifstream cin("euclid3.in");
ofstream cout("euclid3.out");

cin >> t;
while(t--){
    cin >> a >> b >> c;
    int d, x, y;

    euclid(a, b, d, x, y);
    //cout << x << " " << y << "\n";

    if (c % d != 0) cout <<"0 0\n";
    else cout << x * (c / d) << " " << y * (c / d) << "\n";

}

return 0;
}

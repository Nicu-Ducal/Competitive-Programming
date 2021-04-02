#include <bits/stdc++.h>
typedef unsigned int ui;
typedef long long ll;
using namespace std;

ll t, n, d, s;
bool ciur[1000000];

void ciurf(){
    for (ll i = 0; i < 1000001; ++i){
        if (i == 0 || i == 1){
            ciur[i] = 0;
        } else {
            ciur[i] = 1;
        }
    }
    for (ll i = 2; i < 1000001; ++i){
        if (ciur[i]){
            for (ll j = 2*i; j < 1000001; j += i){
                ciur[j] = 0;
            }
        }
    }

}

int main(){

//ifstream cin("ssnd.in");
//ofstream cout("ssnd.out");

ciurf();
d = 1;
s = 1;
int nd = 1;
int m;

cin >> t;

for (int i = 0; i < t; ++i){
    cin >> n;
    if (ciur[n]){
        nd = 2;
        s = n + 1;
        cout << nd << " " << s << "\n";
    }
    else{
        m = 2;
        while (n != 1){
            if (ciur[m] == 1){
                if (n % m == 0){
                    while (n % m == 0){
                        d++;
                        n = n / m;
                    }
                    nd *= d;
                    s = (s + (static_cast<int>(pow(m,d)) - 1) / (i - 1)) % 9973;
                    d = 1;
                    m++;
                }
            }
             else{
                m++;
             }
            }
        cout << nd << " " << s << "\n";
        }

        }




return 0;
}

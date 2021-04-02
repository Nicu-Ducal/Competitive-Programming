#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll t, a, b, c, d, x, y, x1, x2, y1, y2;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> t;
    while(t--){
        cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2;
        ll ta = a, tb = b, tc = c, td = d;
        a -= min(ta, b), b -= min(ta, b);
        c -= min(tc, d), d -= min(tc, d);

        ll left = x - x1;
        ll right = x2 - x;
        ll up = y2 - y;
        ll down = y - y1;
        bool ok = 1;

        //cout << a << " " << b << " " << c<< " " << d << "\n";
        //cout << left << " " << right << " " << up << " " << down << " \n";
        if (a == b){
            if(!left and !right and ta != 0 and tb != 0)
                ok = 0;
        }
        else if (a > b){
            if (left < a)
                ok = 0;
        }
        else{
            if (right < b)
                ok = 0;
        }

        if(ok){
            if (c == d){
                if (!up and !down and tc != 0 and td != 0)
                    ok = 0;
            }
            else if (c > d){
                if (down < c)
                    ok = 0;
            }
            else{
                if (up < d)
                    ok = 0;
            }
        }

        if (ok) cout << "Yes\n";
        else cout << "No\n";
    }


    return 0;
}

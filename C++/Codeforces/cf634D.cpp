#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define len length()
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll a[9][9], t;
string s;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> t;
    while(t--){
        for (int i = 0; i < 9; i++){
            cin >> s;
            for(int j = 0; j < 9; j++)
                a[i][j] = s[j] - '0';
        }

        a[0][0] = (a[0][0] != 9) ? (a[0][0] + 1) % 10 : 1;
        a[1][3] = (a[1][3] != 9) ? (a[1][3] + 1) % 10 : 1;
        a[2][6] = (a[2][6] != 9) ? (a[2][6] + 1) % 10 : 1;
        a[3][1] = (a[3][1] != 9) ? (a[3][1] + 1) % 10 : 1;
        a[4][4] = (a[4][4] != 9) ? (a[4][4] + 1) % 10 : 1;
        a[5][7] = (a[5][7] != 9) ? (a[5][7] + 1) % 10 : 1;
        a[6][2] = (a[6][2] != 9) ? (a[6][2] + 1) % 10 : 1;
        a[7][5] = (a[7][5] != 9) ? (a[7][5] + 1) % 10 : 1;
        a[8][8] = (a[8][8] != 9) ? (a[8][8] + 1) % 10 : 1;


        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
                cout << a[i][j];
            cout<<"\n";
        }
    }



    return 0;
}

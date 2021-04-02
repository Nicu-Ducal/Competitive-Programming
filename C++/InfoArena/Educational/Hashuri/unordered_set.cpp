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

ll n, c, num;
unordered_set<ll> owo;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("hashuri.in");
    ofstream cout("hashuri.out");

    cin >> n;
    while(n--){
        cin >> c >> num;
        switch(c){
            case 1:
                owo.insert(num);
                break;
            case 2:
                if (owo.find(num) != owo.end())
                    owo.erase(num);
                break;
            case 3:
                cout << (owo.find(num) != owo.end()) << "\n";
        }
    }


    return 0;
}

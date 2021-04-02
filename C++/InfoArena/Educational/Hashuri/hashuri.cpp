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

ll n, op, num;
class Hash{
    public:
        static const ll MOD = 700001;
        ll n;
        vector<ll> h[MOD];

        Hash(int val){
            n = val;
            //fill(all(h), 0);
        }

        vector<ll>::iterator find(int val){
            int i = val % MOD;
            vector<ll>::iterator it;
            for (it = h[i].begin(); it != h[i].end(); it++){
                if (*it == val)
                    return it;
            }
            return h[i].end();
        }

        void insert(ll val){
            int i = val % MOD;
            if (find(val) == h[i].end())
                h[i].pb(val);
        }

        void erase(ll val){
            int i = val % MOD;
            if (find(val) != h[i].end())
                h[i].erase(find(val));
        }
};


int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("hashuri.in");
    ofstream cout("hashuri.out");

    cin >> n;
    Hash *owo = new Hash(n);
    for (int i = 0; i < n; i++){
        cin >> op >> num;
        switch(op){
            case 1:
                owo->insert(num);
                break;
            case 2:
                owo->erase(num);
                break;
            case 3:
                cout << (owo->find(num) != owo->h[num % owo->MOD].end()) << "\n";
        }
    }

    return 0;
}

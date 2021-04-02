#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll n, op, x;
set <ll> heap;
vector <ll> order;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("heapuri.in");
    ofstream cout("heapuri.out");

    order.pb(-1);
    cin >> n;
    while(n--){
        cin >> op;
        if (op == 1 || op == 2)
            cin >> x;
        if (op == 1){
            heap.insert(x);
            order.pb(x);
        }
        else if (op == 2){
            heap.erase(order[x]);
        }
        else
            cout << *heap.begin() << "\n";
    }

    return 0;
}

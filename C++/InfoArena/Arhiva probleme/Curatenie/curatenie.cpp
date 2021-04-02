#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

int n, k, in[500005], pre[500005];
pair<int,int> arb[500005];

int inFind(int val, int i, int j){
    for (int m = i; i <= j; m++)
        if (val == in[m])
            return m;
}

int buildTree(int i, int j){
    if (i > j)
        return 0;
    int node = pre[k++];
    if (i == j)
        return node;
    int inIndex = inFind(node, i, j);
    arb[node].fi = buildTree(i, inIndex - 1);
    arb[node].se = buildTree(inIndex + 1, j);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("curatenie.in");
    ofstream cout("curatenie.out");

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> in[i];
    for(int i = 0; i < n; i++)
        cin >> pre[i];

    buildTree(0, n - 1);
    for(ll i = 1; i <= n; i++)
        cout << arb[i].fi << " " << arb[i].se << "\n";

    return 0;
}

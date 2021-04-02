#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << "\n"
#define all(x) (x).begin(),(x).end()
#define len length()
#define sz size()
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>

using ull = unsigned long long;
using ll = long long;
using namespace std;

const int MAXN = 130;
const int INF = INT_MAX;
ll t, n, m;
string g[130];
int viz[MAXN * MAXN];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("vila.in");
    //ofstream cout("vila.out");

    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> g[i];
    }


    return 0;
}

#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

const int maxN = 100005;
int n, k, trupe[maxN], dfs[maxN], x, y;
bool viz[maxN];
set <int> ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("freakadebunic.in");
    ofstream cout("freakadebunic.out");

    dfs[1] = 0, viz[1] = 1;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
        cin >> trupe[i];
    for (int i = 1; i <= n - 1; i++){
        cin >> x >> y;
        dfs[max(x,y)] = min(x,y);
    }

    for (int i = 0; i < k; i++){
        ll nod = trupe[i];
        while(true){
            if (!viz[nod]){
                viz[nod] = 1;
                nod = dfs[nod];
            }
            else{
                ans.insert(nod);
                break;
            }
        }
    }

    cout << ans.size() << "\n";
    for (auto &it : ans)
        cout << it << " ";

    return 0;
}

#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll n, m, ins, p, mat[1005][1005], ni, np;
char viz[1005][1005];

void dfs(ll i, ll j){
    if (i == 0 || i == n - 1 || j == 0 || j == m - 1){
        if(mat[i][j] == 1){
            p = 1;
            viz[i][j] = 'p';
            return;
        }
        else
            return;
    }

    if (viz[i - 1][j] == 'p' || viz[i + 1][j] == 'p' || viz[i][j + 1] == 'p' || viz[i][j - 1] == 'p'){
        viz[i][j] = 'p';
        return;
    }
    if (viz[i - 1][j] == 'i' || viz[i + 1][j] == 'i' || viz[i][j + 1] == 'i' || viz[i][j - 1] == 'i'){
        viz[i][j] = 'i';
        return;
    }

    if (mat[i - 1][j])
        dfs(i - 1, j);
    else if (mat[i + 1][j])
        dfs(i + 1, j);
    else if (mat[i][j - 1])
        dfs(i, j - 1);
    else if (mat[i][j + 1])
        dfs(i, j + 1);

    if (p){
        np++;
        p = 0;
    }

    else if (ins){
        ni++;
        ins = 0;
    }

    return;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    //ifstream cin("lac.in");
    //ofstream cout("lac.out");

    cin >> n >> m;
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m; j++)
            cin >> mat[i][j];

    for(ll i = 1; i < n - 1; i++)
        for(ll j = 1; j < m - 1; j++){
            if (mat[i][j] == 1){
                ins = 0;
                p = 0;
                dfs(i, j);
            }
        }

    cout << ni << " " << np;



    return 0;
}

#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

const int maxNum = 105;
int suma[maxNum], v[maxNum][maxNum], m, n, k, ans, sum;
int bkt[maxNum];

bool solutie(int k){
    if (k == m)
        return 1;
    return 0;
}

void backtrackingMAX(int k, int a[]){
    for (int i = bkt[k - 1] + 1; i <= n; i++){
        bkt[k] = i;
        sum += a[i];
        if (solutie(k))
            ans = max(ans, sum);
        else
            backtrackingMAX(k + 1, a);
        sum -= a[i];
    }
}

void backtrackingMIN(int k, int a[]){
    for (int i = bkt[k - 1] + 1; i <= n; i++){
        bkt[k] = i;
        sum += a[i];
        if (solutie(k))
            ans = min(ans, sum);
        else
            backtrackingMIN(k + 1, a);
        sum -= a[i];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("blat.in");
    ofstream cout("blat.out");

    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++){
        for (int j = 1; j <= n; j++){
            cin >> v[i][j];
            suma[j] += v[i][j];
        }
    }

    backtrackingMAX(1, suma);
    cout << ans << "\n";

    ans = INT_MAX;
    backtrackingMIN(1, suma);
    cout << ans << "\n";

    int maxans = INT_MIN;
    for (int i = 1; i <= k; i++){
        ans = 0;
        backtrackingMAX(1, v[i]);
        maxans = max(ans, maxans);
    }
    cout << maxans << "\n";

    int minans = INT_MAX;
    for (int i = 1; i <= k; i++){
        ans = INT_MAX;
        backtrackingMIN(1, v[i]);
        minans = min(ans, minans);
    }
    cout << minans << "\n";

    return 0;
}

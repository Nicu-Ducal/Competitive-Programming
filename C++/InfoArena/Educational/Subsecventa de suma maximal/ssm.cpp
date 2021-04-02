#include <bits/stdc++.h>
typedef unsigned int ui;
typedef long long ll;
using namespace std;

int a[6000005], n, sum, newst, st, dr, ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("ssm.in");
    ofstream cout("ssm.out");

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ans = INT_MIN;
    for (int i = 0; i < n; i++){
        sum += a[i];
        if (sum > ans){
            st = newst;
            ans = sum;
            dr = i;
        }
        if (sum < 0)
            newst = i + 1;
        sum = max(sum, 0);
    }

    cout << ans << " " << st + 1 << " " << dr + 1;

    return 0;
}

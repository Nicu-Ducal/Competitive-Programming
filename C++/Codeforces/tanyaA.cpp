#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll n, temp, pr;
vector <int> ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n;
    pr = 0;
    while(n--)
    {
        cin >> temp;
        if (temp == 1) ans.pb(pr);
        pr = temp;
    }
    ans.pb(temp);

    cout << ans.size() - 1 << "\n";
    for (int i = 1; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}

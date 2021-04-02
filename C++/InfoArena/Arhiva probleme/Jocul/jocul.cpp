#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("jocul.in");
    ofstream cout("jocul.out");

    int n, a;
    cin >> n;
    vector <int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.pb(a);
    }

    ll s = 0;
    for (auto x: v)
        s += x;

    bool dp[s / 2 + 1];
    dp[0] = 1;
    for (int i = 1; i <= s / 2; i++)
        dp[i] = 0;

    for (auto x : v)
        for (int i = s / 2; i >= 0; i--)
            if (dp[i])
                if ((i + x) <= s / 2)
                    dp[i + x] = 1;

    for (int i = s / 2; i >= 0; i--)
        if (dp[i])
        {
            if (i > s - i)
                cout << s - i << " " << i;
            else
                cout << i << " " << s - i;
            break;
        }

    return 0;
}

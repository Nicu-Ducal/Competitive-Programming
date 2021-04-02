#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    ll n, left = 0, right = 0; string s;
    cin >> n >> s;

    for (ll i = 0; i < n; i++){
        if (s[i] == ')')
            left++;
        else
            right++;
    }
    if (n % 2 == 1 || (n % 2 == 0 && left != right)){
        cout << "-1";
        return 0;
    }

    ll i = 0, kek = 0, start = 0, ans = 0; bool change = 0;
    while(i != n){
        if (s[i] == ')')
            kek--;

        else if (s[i] == '(')
            kek++;
        if (kek < 0)
            change = 1;

        if (kek == 0){
            if (change)
                ans += (i - start + 1);
            start = i + 1;
            change = 0;
        }
        i++;
    }

    cout << ans;

    return 0;
}

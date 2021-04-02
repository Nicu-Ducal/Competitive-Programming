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

const int INF = INT_MAX;
ll t, n, a, b, l, r, q, x;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> t;
    while (t--){
        cin >> a >> b >> q;
        if (a > b)
            swap(a, b);
        for (int que = 1; que < q; que++){
            cin >> l >> r;

        }
    }
    return 0;
}

/* PYTHON
t = int(input())
while t:
    t -= 1
    s = list(input())
    if (set(s) == {'1'} or set(s) == {'0'}):
        print(''.join(s))
        continue
    ans = [s[0]]
    for i in range(1, len(s)):
        if s[i] == ans[-1]:
            if s[i] == '1':
                ans.append('0')
                ans.append(s[i])
            else:
                ans.append('1')
                ans.append(s[i])
        else:
            ans.append(s[i])
    if (ans[0] == ans[-1]):
        if s[0] == '0':
            ans.append('1');
        else:
            ans.append('0');
    print(''.join(ans))
*/

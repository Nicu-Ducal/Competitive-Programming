#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

int t;
string p, h;

int main(){
ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> t;
    while(t--)
    {
        cin >> p >> h;
        if (p.length() > h.length())
        {
            cout << "NO\n"
            return 0;
        }

    }

return 0;
}

/*
t = int(input())
for case in range(t):
    p = input()
    h = input()
    hlist = list(h)
    hl = len(h)
    plist = list(p)
    pl = len(plist)
    if (pl > hl):
        print("NO")
        continue
    for i in range(0, hl - pl + 1):
        if h[i] in plist:
            if (sorted(plist) == sorted(hlist[i:i+pl])):
                print("YES")
                break
    else:
        print("NO")
        */

#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll n, k;
string s;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n >> k >> s;

    string t = s.substr(0,k);
    cout << n << '\n';
    for (int i = k; i < n; i++)
    {
        t += t[i - k];
    }

    if (t >= s)
    {
        cout << t << '\n';
        return 0;
    }
    else
    {
        for (int i = k - 1; i >= 0; i--)
        {
            if (t[i] == '9') t[i] = '0';
            else {
                ++t[i];
                break;
            }
        }
        for (int i = k; i < n; i++)
            t[i] = t[i - k];
    cout << t << '\n';
    }
    return 0;
}

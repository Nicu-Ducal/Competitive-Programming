#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll n, a, b, c, d;
vector < pair <ll, ll> > v;

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    ll keep = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c >> d;
        ll sum = a + b + c + d;
        if (i == 0) keep = sum;
        v.pb({i + 1, sum});
    }
    sort(v.begin(), v.end(), sortbysec);

    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (v[i].se == keep)
        {
            cout << v.size() - i;
            break;
        }
    }
    return 0;
}

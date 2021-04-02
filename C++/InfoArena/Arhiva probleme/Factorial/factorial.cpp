#include <bits/stdc++.h>
#define MAX 100000000000
typedef unsigned int ui;
typedef long long ll;
using namespace std;

ll p;

ll zero(ll x)
{
    ll m = 5;
    ll put = 0;
    while (m <= x)
    {
        put = put + x / m;
        m *= 5;
    }
    return put;
}

ll bs(ll left, ll right)
{
    ll num = -1;
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        if (zero(mid) > p)
        {
            right = mid - 1;
        }
        else if (zero(mid) < p)
        {
            left = mid + 1;
        }
        else if (zero(mid) == p)
        {
            num = mid;
            right = mid - 1;
            continue;
        }
    }
    return num;
}

int main(){

ifstream cin("fact.in");
ofstream cout("fact.out");

cin >> p;

if (p == 0)
{
    cout << 1;
    return 0;
}

ll left = 5;
ll right = MAX;
cout << bs(left, right);

return 0;
}

#include <bits/stdc++.h>
typedef unsigned int ui;
typedef long long ll;
using namespace std;

ll n, m, x, y;
bool vizx[7510], vizy[7510];
vector <ll> v[7510];
queue <ll> q;
vector <ll> com;
ll fr[7510], nivx[7510], nivy[7510];

int main(){

ifstream cin("graf.in");
ofstream cout("graf.out");

cin >> n >> m >> x >> y;

for (ll i = 0; i < m; i++)
{
    ll a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
}

for (ll i = 1; i <= n; i++)
{
    vizx[i] = vizy[i] = 0;
    nivx[i] = nivy[i] = 0;
}

q.push(x);
nivx[x] = 0;
vizx[x] = 1;
bool flag = 1;
while(!q.empty())
{
    ll curr = q.front();
    q.pop();
    for (auto i : v[curr])
    {
        if(!vizx[i])
        {
            nivx[i] = nivx[curr] + 1;
            vizx[i] = 1;
            if (i == y) flag = 0;
            if (flag) q.push(i);
        }
    }
}

q.push(y);
vizy[y] = 1;
nivy[y] = 0;
flag = 1;
while(!q.empty())
{
    ll curr = q.front();
    q.pop();
    for (auto i : v[curr])
    {
        if(!vizy[i])
        {
            nivy[i] = nivy[curr] + 1;
            vizy[i] = 1;
            if (i == x) flag = 0;
            if (flag) q.push(i);
        }
    }
}

for (ll i = 1; i <= n; i++)
{
    if (nivx[i] + nivy[i] == nivx[y])
        fr[nivx[i]]++;
}

for (ll i = 1; i <= n; i++)
{
    if (nivx[i] + nivy[i] == nivx[y])
    {
        if (i == y)
        {
            com.push_back(y);
        }
        else if (nivx[i] < nivx[y] && fr[nivx[i]] == 1)
                com.push_back(i);
    }
}

cout << com.size() << "\n";
for (auto i : com)
{
    cout << i << " ";
}

return 0;
}

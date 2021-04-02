#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

int n, m, x, y;
vector <int> v[7505];
bool viz1[7505], viz2[7505];
int d1[7505], d2[7505], frec[7505];
queue <int> q1, q2;
vector <int> rsp;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    //ifstream cin("graf.in");
    //ofstream cout("graf.out");

    cin >> n >> m >> x >> y;
    int a, b;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }

    //de la x la y
    q1.push(x);
    viz1[x] = 1;
    d1[x] = 1;

    while(!q1.empty() && !viz1[y])
    {
        int curr = q1.front();
        q1.pop();

        for (auto it : v[curr])
        {
            if (!viz1[it])
            {
                d1[it] = d1[curr] + 1;
                viz1[it] = 1;
                q1.push(it);
            }
        }
    }

    //de la y la x
    q2.push(y);
    viz2[y] = 1;
    d2[y] = 1;

    while(!q2.empty() && !viz2[x])
    {
        int curr = q2.front();
        q2.pop();

        for (auto it : v[curr])
        {
            if (!viz2[it])
            {
                d2[it] = d2[curr] + 1;
                viz2[it] = 1;
                q2.push(it);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (d1[i] + d2[i] == d1[y] + 1)
        {
            frec[d1[i]]++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (d1[i] + d2[i] == d1[y] + 1)
        {
            if (i == y)
                rsp.pb(i);
            else if (d1[i] < d1[y])
                if(frec[d1[i]] == 1)
                    rsp.pb(i);
        }
    }

    cout << rsp.size() << "\n";
    for (auto it : rsp)
        cout << it << " ";

    return 0;
}

#include <bits/stdc++.h>
typedef unsigned int ui;
typedef long long ll;
using namespace std;

int N, M;
bool viz[100010];

vector <int> V[100010];

void dfs(int x)
{
    viz[x] = 1;
    for (int i = 0; i < V[x].size(); i++)
    {
        if(!viz[V[x][i]])
        {
            dfs(V[x][i]);
        }
    }
}

int main()
{
    ifstream cin("dfs.in");
    ofstream cout("dfs.out");

    cin >> N >> M;

    int a, b;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
    }

    int num = 0;
    for (int i = 1; i <= N; i++)
    {
        if (!viz[i])
        {
            dfs(i);
            num++;
        }
    }


    cout << num;


    return 0;
}
